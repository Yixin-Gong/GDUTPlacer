# TODO:Implement CMakeLists.txt

cmake_minimum_required(VERSION 3.22)

project(GDUTPlacer LANGUAGES CXX)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(constraints)
add_subdirectory(database)
add_subdirectory(detail_place)
add_subdirectory(gdut_placer)
add_subdirectory(legalize)
add_subdirectory(params)
add_subdirectory(parser)
add_subdirectory(preplace)
add_subdirectory(scripts)
add_subdirectory(thirdparty)
add_subdirectory(utils)
add_subdirectory(wirelength)
add_subdirectory(writer)

