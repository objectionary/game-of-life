// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

#include "../../include/size.h"
BOOST_AUTO_TEST_CASE(test_size) {
  int n = 20;
  int m = 30;
  Size sz = Size(n, m);
  BOOST_REQUIRE(sz.n == n && sz.m == m);
}
