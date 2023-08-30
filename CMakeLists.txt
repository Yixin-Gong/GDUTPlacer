cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(Violet LANGUAGES CXX)

find_package(Torch REQUIRED PATHS "/usr/local/lib/libtorch")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

set(Boost_NO_BOOST_CMAKE TRUE)
find_package(Boost 1.55.0 REQUIRED)
message(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")

set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "verbose makefile output")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY POSITION_INDEPENDENT_CODE TRUE)

add_subdirectory(GPlace)
