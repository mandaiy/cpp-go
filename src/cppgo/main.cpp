#include <boost/format.hpp>

#include <pybind11/pybind11.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>

#include "cppgo_impl/color.hpp"
#include "cppgo_impl/move.hpp"
#include "cppgo_impl/state.hpp"

#include "features.hpp"

namespace py = pybind11;

using namespace pybind11::literals;


namespace std {
    template <>
    struct hash<std::pair<int, int>> {
        size_t operator()(std::pair<int, int> const& p) const {
            auto hasher = hash<int>();
            return hasher(p.first) ^ hasher(p.second);
        }
    };

}


PYBIND11_MODULE(cppgo, m) {
    py::enum_<cppgo::Color>(m, "Color")
            .value("BLACK", cppgo::Color::BLACK)
            .value("WHITE", cppgo::Color::WHITE)
            .value("EMPTY", cppgo::Color::EMPTY)
            .export_values();

    m.def("opposite_color", &cppgo::opposite_color);

    py::class_<cppgo::Move>(m, "Move")
            .def_static("from_coordinate",
                 &cppgo::Move::from_coordinate,
                 "construct Move object from coordinate and board size",
                 "row"_a, "col"_a, "board_size"_a
            )
            .def_static("from_gtp_string", &cppgo::Move::from_gtp_string)
            .def("raw", &cppgo::Move::raw)
            .def("__repr__", [](cppgo::Move const& v) -> std::string {
                if (v == cppgo::Move::PASS) {
                    return "Move.PASS";
                }

                if (v == cppgo::Move::ANY) {
                    return "Move.ANY";
                }

                if (v == cppgo::Move::INVALID) {
                    return "Move.INVALID";
                }

                return (boost::format("(%1%, %2%)") % v.row() % v.col()).str();
            })
            .def(py::self == py::self)
            .def(py::self != py::self)
            .def_property_readonly_static("ANY",     [](py::object) { return cppgo::Move::ANY; })
            .def_property_readonly_static("INVALID", [](py::object) { return cppgo::Move::INVALID; })
            .def_property_readonly_static("PASS",    [](py::object) { return cppgo::Move::PASS; });

    py::class_<cppgo::State>(m, "State")
            .def(py::init<std::size_t, double, bool, bool>(),
                 "size"_a, "komi"_a = 7.5, "superko_rule"_a = false, "retain_history"_a = false
            )
            .def(py::init<std::size_t, double, bool, int>(),
                 "size"_a, "komi"_a = 7.5, "superko_rule"_a = false, "history_length"_a = 0
            )
            .def_property("current_player",
                          [](cppgo::State const& state) { return state.current_player; },
                          [](cppgo::State& state, cppgo::Color c) { state.current_player = c; },
                          "Opposite of the last played color"
            )
            .def_property("komi",
                          [](cppgo::State const& state) { return state.komi; },
                          [](cppgo::State& state, double komi) { state.komi = komi; },
                          "Komi value"
            )
            .def_property_readonly("board_size",
                                   [](cppgo::State const& state) { return state.board_size(); },
                                   "Return the current board size"
            )
            .def_property_readonly("last_move",
                                   [](cppgo::State const& state) { return state.last_move(); },
                                   "Return the last move"
            )
            .def_property_readonly("history_length",
                                   [](cppgo::State const& state) { return state.history().history_length; },
                                   "Return history length"
            )
            .def_property_readonly("retain_history",
                                   [](cppgo::State const& state) { return state.history().history_length > 0; }
            )
            .def_property_readonly("superko_rule",
                                   [](cppgo::State const& state) { return state.superko_rule(); }
            )
            .def("__str__",
                 [] (cppgo::State const& state) {
                     return state.to_string();
                 }
            )
            .def("copy",
                 [] (cppgo::State const& state) {
                     return cppgo::State(state);
                 },
                 py::return_value_policy::move
            )
            .def("legal_moves",
                 [] (cppgo::State const& state, cppgo::Color c, bool include_eyeish) {
                     auto legals = state.legal_moves(c, include_eyeish);

                     std::unordered_set<std::pair<int, int>> ret;
                     for (auto const& v : legals) {
                         ret.emplace(std::make_pair(v.row(), v.col()));
                     }

                     return ret;
                 },
                 "Generate legal moves for the current state",
                 "color"_a = cppgo::Color::EMPTY, "include_eyeish"_a = false
            )
            .def("is_legal",
                 [](cppgo::State const& state, cppgo::Move const* m, cppgo::Color c) {
                     if (m == nullptr) {
                         return true;
                     }

                     return state.is_legal(*m, c);
                 },
                 "move"_a, "color"_a = cppgo::Color::EMPTY
            )
            .def("is_legal",
                 [](cppgo::State const& state, std::string const& m, cppgo::Color c) {
                     return state.is_legal(cppgo::Move::from_gtp_string(m, state.board_size()), c);
                 },
                 "move"_a, "color"_a = cppgo::Color::EMPTY
            )
            .def("is_legal",
                 [](cppgo::State const& state, std::pair<int, int> const& v, cppgo::Color c) {
                     return state.is_legal(cppgo::Move::from_coordinate(v.first, v.second, state.board_size()), c);
                 },
                 "move"_a, "color"_a = cppgo::Color::EMPTY
            )
            .def("tromp_taylor_score",
                 &cppgo::State::tromp_taylor_score,
                 "Returns tromp taylor score from Color perspective",
                 "color"_a = cppgo::Color::EMPTY
            )
            .def("move_history",
                 &cppgo::State::move_history,
                 "Returns color's move history list",
                 "color"_a
            )
            .def("make_move",
                 [] (cppgo::State& state, cppgo::Move const* m, cppgo::Color c) {
                     if (m == nullptr) {
                         state.make_move(cppgo::Move::PASS, c);
                     }
                     else {
                         state.make_move(*m, c);

                     }
                 },
                 "Apply move to the state as color",
                 "move"_a.none(true), "color"_a = cppgo::Color::EMPTY
            )
            .def("make_move",
                 [] (cppgo::State& state, std::string const& move, cppgo::Color c) {
                     state.make_move(cppgo::Move::from_gtp_string(move, state.board_size()), c);
                 },
                 "Apply move to the state as color",
                 "move"_a, "color"_a = cppgo::Color::EMPTY
            )
            .def("make_move",
                 [] (cppgo::State& state, std::pair<int, int> const& v, cppgo::Color c) {
                    state.make_move(cppgo::Move::from_coordinate(v.first, v.second, state.board_size()), c);
                 },
                 "Apply move to the state as color",
                 "move"_a, "c.lor"_a = cppgo::Color::EMPTY);

    m.attr("Pass") = nullptr;


    py::module m_features = m.def_submodule("features");

    m_features.def("board_i",
                   [] (cppgo::State const& state, std::size_t i, cppgo::Color c) {
                       return cppgo::board_i(state, i, c);
                   },
                   "Get the i-th before board feature. If c = Color.EMPTY, returns both color's features",
                   "state"_a, "i"_a, "color"_a = cppgo::Color::EMPTY
    );
    m_features.def("history_n",
                   [] (cppgo::State const& state, std::size_t n, cppgo::Color c) {
                       return cppgo::history_n(state, n, c);
                   },
                   "Get the board history from n-th before. If c = Color.EMPTY, returns both color's features",
                   "state"_a, "i"_a, "color"_a = cppgo::Color::EMPTY
    );

    m_features.def("black",   &cppgo::black);
    m_features.def("white",   &cppgo::white);
}

