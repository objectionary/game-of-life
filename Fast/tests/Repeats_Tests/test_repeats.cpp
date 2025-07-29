// SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <boost/test/unit_test.hpp>

#include "../../include/repeats.h"

BOOST_AUTO_TEST_CASE(test_repeats) {
  int n = 30;
  Repeats r = Repeats(n);
  BOOST_REQUIRE(r.rep == n);
}
