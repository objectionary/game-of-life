// SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <boost/test/unit_test.hpp>

#include "../../include/cell.h"
#include "../../include/field.h"
#include "../../include/parse.h"

BOOST_AUTO_TEST_CASE(test_points_get) {
  Parse p = Parse();
  auto res = p.point("11x3");
  BOOST_REQUIRE(res.first == 11 && res.second == 3);
  res = p.point("5x100");
  BOOST_REQUIRE(res.first == 5 && res.second == 100);
  res = p.point("3x1");
  BOOST_REQUIRE(res.first == 3 && res.second == 1);
}
