#include <boost/format.hpp>

#include "features.hpp"

#include "cppgo_impl/state.hpp"


namespace py = pybind11;

namespace cppgo {

    void check(State const& state, std::size_t i) {
        if (i < 0 or i >= state.history().history_length) {
            auto message = (boost::format("argument i must be in the range of [0, %1%), i was %2%")
                                % state.history().history_length
                                % i).str();
            throw std::invalid_argument(message);
        }
    }

    py::array_t<float> color_impl(State const& state, Color c) {
        auto board_size = static_cast<std::size_t>(state.board_size());
        auto array_size = board_size * board_size;

        auto ret = new float[array_size]();

        if (state.current_player == c) {
            std::fill_n(ret, array_size, 1.0f);
        }

        return py::array_t<float>({1, state.board_size(), state.board_size()}, ret, py::capsule(ret, [] (void* f) {
            auto p = reinterpret_cast<float*>(f);
            delete[] p;
        }));
    }

    py::array_t<float> black(State const& state) {
        return color_impl(state, Color::BLACK);
    }

    py::array_t<float> white(State const& state) {
        return color_impl(state, Color::WHITE);
    }

    py::array_t<float> board(State const& state) {
        return board_i(state, 0);
    }

    py::array_t<float> board_i(State const& state, std::size_t i) {
        check(state, i);

        auto board_size = static_cast<std::size_t>(state.board_size());
        auto plane_size = board_size * board_size;
        auto array_size = plane_size * 2;

        auto ret = new float[array_size]();

        auto const& history_1 = state.history().history(state.current_player);
        auto const& history_2 = state.history().history(opposite_color(state.current_player));

        if (history_1.size() <= i or history_2.size() <= i) {
            return py::array_t<float>({2, state.board_size(), state.board_size()}, ret, py::capsule(ret, [] (void* f) {
                auto p = reinterpret_cast<float*>(f);
                delete[] p;
            }));
        }

        auto itr_1 = std::begin(history_1);
        auto itr_2 = std::begin(history_2);

        std::advance(itr_1, i);
        std::advance(itr_2, i);

        auto const& board_1 = *itr_1;
        auto const& board_2 = *itr_2;

        std::copy(std::begin(board_1), std::end(board_1), ret);
        std::copy(std::begin(board_2), std::end(board_2), ret + plane_size);

        return py::array_t<float>({2, state.board_size(), state.board_size()}, ret, py::capsule(ret, [] (void* f) {
            auto p = reinterpret_cast<float*>(f);
            delete[] p;
        }));
    }

    py::array_t<float> board_n(State const& state, std::size_t n) {
        check(state, n - 1);

        auto board_size = static_cast<std::size_t>(state.board_size());
        auto plane_size = board_size * board_size;
        auto array_size = plane_size * 2 * n;

        auto ret = new float[array_size]();

        auto const& history_1 = state.history().history(state.current_player);
        auto const& history_2 = state.history().history(opposite_color(state.current_player));

        auto itr_1 = std::begin(history_1);
        auto itr_2 = std::begin(history_2);

        int i = 0;
        auto length = history_1.size();

        std::size_t offset = 0;

        while (i < n and i < length) {
            auto const& board_1 = *itr_1;
            auto const& board_2 = *itr_2;

            std::copy(std::begin(board_1), std::end(board_1), ret + offset);
            std::copy(std::begin(board_2), std::end(board_2), ret + offset + plane_size);

            ++itr_1; ++itr_2;
            offset += 2 * plane_size;
            i += 1;
        }

        return py::array_t<float>({2 * n, board_size, board_size}, ret, py::capsule(ret, [] (void* f) {
            auto p = reinterpret_cast<float*>(f);
            delete[] p;
        }));
    }

    py::array_t<float> color_n(State const& state, std::size_t n, Color c) {
        check(state, n);

        auto board_size = static_cast<std::size_t>(state.board_size());
        auto plane_size = board_size * board_size;
        auto array_size = plane_size * n;

        auto ret = new float[array_size]();

        auto const& history = state.history().history(c);
        auto itr = std::begin(history);

        int i = 0;
        auto length = history.size();

        std::size_t offset = 0;

        while (i < n and i < length) {
            auto const &board = *itr;
            std::copy(std::begin(board), std::end(board), ret + offset);

            ++itr;
            offset += plane_size;
            i += 1;
        }

        return py::array_t<float>({n, board_size, board_size}, ret, py::capsule(ret, [] (void* f) {
            auto p = reinterpret_cast<float*>(f);
            delete[] p;
        }));
    }

}
