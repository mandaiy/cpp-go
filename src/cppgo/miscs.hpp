#ifndef CPPGO_MISCS_HPP
#define CPPGO_MISCS_HPP

#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>


namespace cppgo {

    class State;

    void apply_moves(State& state, pybind11::array_t<int> const& moves);

}

#endif //CPPGO_MISCS_HPP
