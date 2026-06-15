# SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
# SPDX-License-Identifier: MIT

add_library(slow_lib STATIC
    src/cell.cpp
    src/field.cpp
    src/objects.cpp
    src/parse.cpp
)

target_include_directories(slow_lib PUBLIC include)
target_link_libraries(slow_lib PUBLIC Boost::program_options)
target_compile_options(slow_lib PRIVATE -Wall -Wextra -Wpedantic)

add_executable(slow_life src/main.cpp)
target_link_libraries(slow_life PRIVATE slow_lib)

add_executable(slow_test
    tests/Cell_Tests/test_cell_live.cpp
    tests/Field_Tests/test_build.cpp
    tests/Field_Tests/test_count.cpp
    tests/Field_Tests/test_live.cpp
    tests/Field_Tests/test_with.cpp
    tests/Parse_Tests/test_points_get.cpp
)
target_link_libraries(slow_test PRIVATE slow_lib Boost::unit_test_framework)

add_test(NAME slow_test COMMAND slow_test --log_level=all)
