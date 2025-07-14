// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <boost/test/unit_test.hpp>

#include "../../include/arg_parse.h"

BOOST_AUTO_TEST_CASE(test_arg_parse_size) {
  for (int i = 0; i < 10; i++) {
    int n = rand();
    int m = rand();
    string s = to_string(n) + "x" + to_string(m);
    pair<int, int> res = Parse::get_size(s);
    if (!(res.first == n && res.second == m)) {
      BOOST_FAIL("didn't work with n = " << n << " and m = " << m);
    }
  }
}
