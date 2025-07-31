
// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <boost/test/unit_test.hpp>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "../../include/field.h"

using std::pair;
using std::set;
using std::string;
using std::vector;

void checker(vector<pair<int,int>> check, const set<pair<int, int>>& res, int n, int m,
  const string& test_case) {
  Field f = Field(Int(n), Int(m));
  f = f.rec_add(f, std::move(check), 0);
  auto g = f.live().field();
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j].status()) {
        cnt++;
        if (res.count({i + 1, j + 1}) == 0) {
          BOOST_FAIL(" in grid should be  {" << i + 1 << "," << j + 1
                                             << "}, but not in case "
                                             << test_case);
        }
      }
    }
  }
  if (cnt != res.size()) {
    BOOST_FAIL("should be " << res.size() << " number of points, but get "
                            << cnt << " in test case " << test_case);
  }
}

BOOST_AUTO_TEST_CASE(test_field_live) {
  int n = 20;
  int m = 20;
  vector<pair<int,int>> check1 = {{2,3}, {2,4}, {3,2}, {3,3}, {3,4}, {3,5}};
  set<pair<int, int>> res1({{3, 2}, {3, 5}, {4, 3}, {4, 4}, {2, 2}, {2, 5}});
  checker(check1, res1, n, m, "first");
  vector<pair<int,int>> check2 = {
    {2,2}, {2,3}, {2,4}, {3,2}, {3,4}, {4,2}, {4,4}, {5,3}};
  set<pair<int, int>> res2({{1, 3}, {2, 2}, {2, 4}, {3, 1}, {3, 2}, {3, 4},
    {3, 5}, {4, 2}, {4, 4}, {5, 3}});
  checker(check2, res2, n, m, "second");
  vector<pair<int,int>> check3 = {
    {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {2,2}, {2,3}, {3,2}, {3,3}, {4,3}};
  set<pair<int, int>> res3({{1, 1}, {1, 4}, {3, 4}, {4, 2}, {4, 3}});
  checker(check3, res3, n, m, "third");
}
