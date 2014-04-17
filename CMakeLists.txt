# Copyright (C) 2013-2014 David Capello

cmake_minimum_required(VERSION 2.8)

# Search .cmake files inside cmake/ directory
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# C++11/14/17 Support
find_package(CxxSupport)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/cxx_config.h.cmakein
               ${CMAKE_CURRENT_BINARY_DIR}/cxx_config.h @ONLY)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# Snippets
add_subdirectory(filesystem)
add_subdirectory(hello_world)
add_subdirectory(raii)
