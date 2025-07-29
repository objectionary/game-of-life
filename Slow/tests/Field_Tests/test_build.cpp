// SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <boost/test/unit_test.hpp>

#include "../../include/field.h"

BOOST_AUTO_TEST_CASE(test_field_build) {
  int n = 15;
  int m = 10;
  set<pair<int, int>> p = {
    {2, 7}, {3, 7}, {6, 8}, {1, 1}, {3, 3}, {10, 10}, {14, 1}};
  vector<pair<int,int>> r= {{2, 7}, {3, 7}, {6, 8}, {1, 1}, {3, 3}, {10, 10}, {14, 1}};
  Field f = Field(Int(n), Int(m));
  auto g = f.rec_add(f, r, 0).field();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j].status()) {
        cnt++;
        if (p.count({i + 1, j + 1}) == 0) {
          BOOST_FAIL(
            " in grid should be  {" << i + 1 << "," << j + 1 << "}, but not");
        }
      }
    }
  }
  BOOST_REQUIRE(cnt == p.size());
}
