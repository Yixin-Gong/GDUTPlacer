set(TARGET_NAME main)

file(GLOB CPP_SOURCES
        Gplace.h
        Gplace.cc)

file(GLOB BIN_SOURCES
        main.h
        main.cc)

set(INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/..)

set(LINK_LIBS
        preplace_cxx
        placemnet_cxx
        utils_cxx
        parser_cxx
        writer_cxx)

add_executable(GPlace ${CPP_SOURCES} ${BIN_SOURCES})
target_include_directories(GPlace PUBLIC ${INCLUDE_DIRS})
target_link_directories(GPlace PUBLIC ${LINK_LIBS})