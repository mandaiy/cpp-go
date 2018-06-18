cmake_minimum_required(VERSION 3.1.3)

project(cppgo)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_RELEASE        "${CMAKE_CXX_FLAGS_RELEASE}        -Wall -Wextra -march=native -Wno-deprecated -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG          "${CMAKE_CXX_FLAGS_DEBUG}          -Wall -Wextra -march=native -fno-inline")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -Wall -Wextra -march=native -fno-inline")

include(cmake/googletest.cmake)

set(CPPGO_SRC_ROOT_DIR ${PROJECT_SOURCE_DIR}/src)
set(CPPGO_IMPL_DIR ${PROJECT_SOURCE_DIR}/src/cppgo_impl)

add_subdirectory(ext/pybind11)
add_subdirectory(src)
add_subdirectory(tst)


if     (CMAKE_BUILD_TYPE MATCHES Release)
    message (STATUS "Set compiler flags (Release): ${CMAKE_CXX_FLAGS_RELEASE}")
elseif (CMAKE_BUILD_TYPE MATCHES Debug)
    message (STATUS "Set compiler flags (Debug): ${CMAKE_CXX_FLAGS_DEBUG}")
elseif (CMAKE_BUILD_TYPE MATCHES RelWithDebInfo)
    message (STATUS "Set compiler flags (RelWithDebInfo): ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
endif  ()
