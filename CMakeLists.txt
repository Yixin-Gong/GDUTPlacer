cmake_minimum_required(VERSION 3.12)
project(ICCAD-contest-2023-problemB)
set(SOURCES
        main.cpp)
add_executable(ICCAD-contest-2023-problemB ${SOURCES})
target_link_libraries(ICCAD-contest-2023-problemB
        PRIVATE
        ${PROJECT_SOURCE_DIR}/parser
        )