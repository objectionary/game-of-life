# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.16...3.31)
project(Life
    VERSION 1.0.0
    DESCRIPTION "John Conway's Game of Life in C++"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(POLICY CMP0167)
  cmake_policy(SET CMP0167 OLD)
endif()

find_package(Boost QUIET COMPONENTS program_options unit_test_framework)

if(NOT Boost_FOUND)
  message(FATAL_ERROR
    "Boost (program_options, unit_test_framework) is required.\n"
    "Install it with your system package manager:\n"
    "  Arch:      sudo pacman -S boost\n"
    "  Ubuntu:    sudo apt-get install libboost-all-dev\n"
    "  macOS:     brew install boost\n"
    "\n"
    "Or point CMake to a custom Boost installation:\n"
    "  cmake -B build -DBOOST_ROOT=/path/to/boost\n"
  )
endif()

enable_testing()

add_subdirectory(cpp/fast)
add_subdirectory(cpp/slow)
