#ifndef CPPGO_FEATURES_HPP
#define CPPGO_FEATURES_HPP

#include <list>
#include <vector>

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "cppgo_impl/color.hpp"


namespace cppgo {

    class State;

    pybind11::array_t<float> board_i(State const& state, std::size_t i, Color c);

    pybind11::array_t<float> history_n(State const& state, std::size_t n, Color c);

    pybind11::array_t<float> black(State const& state);

    pybind11::array_t<float> white(State const& state);
}

#endif //CPPGO_FEATURES_HPP
