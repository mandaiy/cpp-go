#include "features.hpp"

#include "cppgo_impl/state.hpp"


namespace py = pybind11;

namespace cppgo {

    py::array_t<float> board(State const& state) {
        auto board_size = state.board_size();

        auto const& black_board = state.black_board();
        auto const& white_board = state.white_board();

        std::size_t array_size = black_board.size() + white_board.size();

        auto ret = new float[array_size]();

        if (state.current_player == Color::BLACK) {
            std::copy(std::begin(black_board), std::end(black_board), ret);
            std::copy(std::begin(white_board), std::end(white_board), ret + black_board.size());
        }
        else {
            std::copy(std::begin(white_board), std::end(white_board), ret);
            std::copy(std::begin(black_board), std::end(black_board), ret + white_board.size());
        }

        return py::array_t<float>({2, board_size, board_size}, ret, py::capsule(ret, [] (void* f) {
            auto p = reinterpret_cast<float*>(f);
            delete[] p;
        }));
    }

    py::array_t<float> board_n(State const& state, int n) {
        auto board_size = state.board_size();

        std::size_t plane_size = static_cast<std::size_t>(board_size * board_size);
        std::size_t array_size = plane_size * 2 * n;

        auto ret = new float[array_size]();

        auto const& history_1 = state.history().history(state.current_player);
        auto const& history_2 = state.history().history(opposite_color(state.current_player));

        std::size_t offset = 0;
        for (auto const& history : {history_1, history_2}) {
            int i = 0;
            auto itr = std::begin(history);
            while (i < n and i < history.size()) {
                auto const &board = *itr;
                std::copy(std::begin(board), std::end(board), ret + offset);
                offset += plane_size;

                ++itr;
                ++i;
            }

            while (i < n) {
                offset += plane_size;
                ++i;
            }
        }

        return py::array_t<float>({2 * n, board_size, board_size}, ret, py::capsule(ret, [] (void* f) {
            auto p = reinterpret_cast<float*>(f);
            delete[] p;
        }));
    }

}
