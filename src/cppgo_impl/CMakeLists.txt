file(GLOB SRCS *.cpp)

add_library(cppgo_impl ${SRCS})

set_target_properties(cppgo_impl PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

