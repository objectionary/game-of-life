// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <boost/test/unit_test.hpp>

#include "../../include/arg_parse.h"
#include "../../include/field.h"
#include "../../include/size.h"

BOOST_AUTO_TEST_CASE(test_count_alive) {
  int n = 20;
  int m = 20;
  vector<string> check = {
    "3x3", "2x2", "2x4", "4x2", "4x4", "5x5", "6x5", "7x5", "1x4"};
  Parse p = Parse();
  vector<pair<int, int>> put = Parse::get_alive(check, n, m);
  Size sz = Size(n, m);
  Field f = Field(sz);
  f.read_and_set(put);
  BOOST_REQUIRE(f.count(2, 2, sz) == 4);
  BOOST_REQUIRE(f.count(4, 3, sz) == 3);
  BOOST_REQUIRE(f.count(7, 7, sz) == 0);
}
