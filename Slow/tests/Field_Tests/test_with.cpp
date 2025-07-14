// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <boost/test/unit_test.hpp>

#include "../../include/cell.h"
#include "../../include/field.h"

BOOST_AUTO_TEST_CASE(test_field_with) {
  int n = 20;
  int m = 20;
  vector<pair<int,int>> check = {
    {3,3}, {2,2}, {2,4}, {4,2}, {4,4}, {5,5}, {6,5}, {7,5}, {1,4}};
  Field f = Field(Int(n), Int(m));
  f = f.rec_add(f, check, 0);
  Cell add = Cell(Bool(true));
  f = f.with(1, 2, add);
  f = f.with(3, 2, add);
  add = Cell(Bool(false));
  f = f.with(2, 2, add);
  f = f.with(0, 3, add);
  auto g = f.field();
  BOOST_REQUIRE(g[1][2].status());
  BOOST_REQUIRE(g[3][2].status());
  BOOST_REQUIRE(!g[2][2].status());
  BOOST_REQUIRE(!g[0][3].status());
}
