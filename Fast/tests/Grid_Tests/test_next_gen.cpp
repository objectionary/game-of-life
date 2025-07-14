// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <boost/test/unit_test.hpp>

#include "../../include/arg_parse.h"
#include "../../include/field.h"
#include "../../include/grid.h"
#include "../../include/size.h"

pair<vector<string>, vector<pair<int, int>>> get_grid(int n, int m, int it) {
  vector<string> check;
  vector<pair<int, int>> p;
  for (int i = 0; i < it; i++) {
    int x = rand() % n + 1;
    int y = rand() % m + 1;
    p.push_back({x, y});
    check.push_back(to_string(x) + "x" + to_string(y));
  }
  return {check, p};
}

BOOST_AUTO_TEST_CASE(test_read_and_set_field) {
  for (int i = 0; i < 10; i++) {
    int n = abs(rand()) % 100 + 20;
    int m = abs(rand()) % 100 + 20;
    int it = rand() % 20 + 1;
    auto g = get_grid(n, m, it);
    vector<string> check = g.first;
    vector<pair<int, int>> po = g.second;
    Parse p = Parse();
    vector<pair<int, int>> put = Parse::get_alive(check, n, m);
    Size sz = Size(n, m);
    Field f = Field(sz);
    f.read_and_set(put);
    for (int i = 0; i < it; i++) {
      if (!f.f[po[i].first - 1][po[i].second - 1].getCurState()) {
        BOOST_FAIL("should be true {" << po[i].first - 1 << ","
                                      << po[i].second - 1 << "}, but not");
      }
    }
  }
}
