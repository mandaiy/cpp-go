cmake_minimum_required(VERSION 3.1.3)

project(cppgo)

set(CMAKE_CXX_STANDARD 14)

include(cmake/googletest.cmake)

set(CPPGO_SRC_ROOT_DIR ${PROJECT_SOURCE_DIR}/src)
set(CPPGO_IMPL_DIR ${PROJECT_SOURCE_DIR}/src/cppgo_impl)

add_subdirectory(ext/pybind11)
add_subdirectory(src)
add_subdirectory(tst)
