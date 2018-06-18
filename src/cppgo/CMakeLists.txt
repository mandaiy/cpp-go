file(GLOB SRCS *.cpp)

pybind11_add_module(cppgo ${SRCS})

add_dependencies(cppgo cppgo_impl)

target_link_libraries(cppgo PRIVATE cppgo_impl)
