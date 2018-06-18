file (GLOB SRCS *.cpp)

include_directories(${CPPGO_IMPL_DIR})

enable_testing()

add_executable(cppgo_impl_test ${SRCS})

add_dependencies(cppgo_impl_test cppgo_impl)
add_dependencies(cppgo_impl_test googletest)

target_link_libraries(cppgo_impl_test
        libgmock.a
        libgtest.a
        libgtest_main.a
        cppgo_impl
        pthread)

add_test(
        NAME cppgo_impl_test
        COMMAND $<TARGET_FILE:cppgo_impl_test>
)
