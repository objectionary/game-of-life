// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <gtest/gtest.h>

#include "../../include/arg_parse.h"
#include "../../include/field.h"
#include "../../include/size.h"

TEST(CountAliveTest, CountAliveNeighbors) {
    int n = 20;
    int m = 20;
    std::vector<std::string> check = {
        "3x3", "2x2", "2x4", "4x2", "4x4", "5x5", "6x5", "7x5", "1x4"};
    Parse p = Parse();
    std::vector<std::pair<int, int>> put = Parse::get_alive(check, n, m);
    Size sz = Size(n, m);
    Field f = Field(sz);
    f.read_and_set(put);
    EXPECT_EQ(f.count(2, 2, sz), 4);
    EXPECT_EQ(f.count(4, 3, sz), 3);
    EXPECT_EQ(f.count(7, 7, sz), 0);
}
