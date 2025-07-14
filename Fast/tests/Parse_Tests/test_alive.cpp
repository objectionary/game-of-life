// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <boost/test/unit_test.hpp>

#include "../../include/arg_parse.h"

pair<vector<string>, vector<pair<int, int>>> gen_grid(int n, int m, int it) {
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

BOOST_AUTO_TEST_CASE(test_arg_parse_alive) {
  for (int i = 0; i < 10; i++) {
    int n = abs(rand());
    int m = abs(rand());
    int it = rand() % 20 + 1;
    auto g = gen_grid(n, m, it);
    vector<string> check = g.first;
    vector<pair<int, int>> p = g.second;

    vector<pair<int, int>> res = Parse::get_alive(check, n, m);
    for (int i = 0; i < it; i++) {
      if (!(res[i].first == p[i].first && res[i].second == p[i].second)) {
        BOOST_FAIL("didn't work for pair {"
                   << p[i].first << "," << p[i].second << "}"
                   << " ,the actual result is {" << res[i].first << ","
                   << res[i].second << "}");
      }
    }
  }
}
