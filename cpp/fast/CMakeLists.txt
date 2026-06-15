# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

add_library(fast_lib STATIC
    src/arg_parse.cpp
    src/args_check.cpp
    src/args_process.cpp
    src/args_valid.cpp
    src/cell.cpp
    src/field.cpp
    src/game.cpp
    src/grid.cpp
    src/repeats.cpp
    src/size.cpp
)

target_include_directories(fast_lib PUBLIC include)
target_link_libraries(fast_lib PUBLIC Boost::program_options)
target_compile_options(fast_lib PRIVATE -Wall -Wextra -Wpedantic)

add_executable(fast_life src/main.cpp)
target_link_libraries(fast_life PRIVATE fast_lib)

add_executable(fast_test
    tests/Field_Tests/test_alive.cpp
    tests/Field_Tests/test_read_and_set.cpp
    tests/Grid_Tests/test_next_gen.cpp
    tests/Parse_Tests/test_alive.cpp
    tests/Parse_Tests/test_size.cpp
    tests/Repeats_Tests/test_repeats.cpp
    tests/Size_Tests/test_size.cpp
)
target_link_libraries(fast_test PRIVATE fast_lib Boost::unit_test_framework)

add_test(NAME fast_test COMMAND fast_test --log_level=all)
