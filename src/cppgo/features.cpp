#include <stdexcept>

#include <boost/format.hpp>

#include "cppgo/features.hpp"

#include "cppgo_impl/state.hpp"
#include "cppgo_impl/features.hpp"


namespace py = pybind11;

namespace cppgo {

    template <typename T, typename TInt>
    py::array_t<T> make_pyarray(T* array_ptr, std::initializer_list<TInt> shape) {
        return py::array_t<float>(shape, array_ptr, py::capsule(array_ptr, [](void* f) {
            delete[] reinterpret_cast<T*>(f);
        }));
    }

    template <typename T>
    T* to_ptr(std::vector<T> const& v) {
        auto ptr = new T[v.size()]();

        std::copy(std::begin(v), std::end(v), ptr);

        return ptr;
    }

    py::array_t<float> black(State const& state) {
        return make_pyarray(to_ptr(color_impl<float>(state, Color::BLACK)),
                            {1, state.board_size(), state.board_size()});
    }

    py::array_t<float> white(State const& state) {
        return make_pyarray(to_ptr(color_impl<float>(state, Color::WHITE)),
                            {1, state.board_size(), state.board_size()});
    }


    py::array_t<float> board_i(State const& state, int i, Color c) {
        auto const length = state.history().history_length;

        if (i < 0 or state.history().history_length <= i) {
            throw std::invalid_argument((boost::format("i must be in [0, %1%), which was %2%") % length % i).str());
        }

        float* ptr = (c == Color::EMPTY) ? to_ptr(board_i_impl<float>(state, i))
                                         : to_ptr(board_i_color_impl<float>(state, i, c));

        return make_pyarray(ptr, {2, state.board_size(), state.board_size()});
    }

    py::array_t<float> history_n(State const& state, int n, Color c) {
        auto const length = state.history().history_length;

        if (n < 0 or length <= n) {
            throw std::invalid_argument((boost::format("n must be in [0, %1%), which was %2%") % length % n).str());
        }

        float* ptr = (c == Color::EMPTY) ? to_ptr(history_n_impl<float>(state, n))
                                         : to_ptr(history_n_color_impl<float>(state, n, c));

        return make_pyarray(ptr, {2 * (n + 1), state.board_size(), state.board_size()});
    }

}
