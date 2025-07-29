// SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <boost/test/unit_test.hpp>

#include "../../include/field.h"

BOOST_AUTO_TEST_CASE(test_field_count) {
  int n = 20;
  int m = 20;
  vector<pair<int,int>> check = {
    {3,3}, {2,2}, {2,4}, {4,2}, {4,4}, {5,5}, {6,5}, {7,5}, {1,4}};
  Field f = Field(Int(n), Int(m));
  f = f.rec_add(f, check, 0);
  BOOST_REQUIRE(f.count(2, 2).get() == 4);
  BOOST_REQUIRE(f.count(4, 3).get() == 3);
  BOOST_REQUIRE(f.count(7, 7).get() == 0);
}
