// SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
// SPDX-License-Identifier: MIT

#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

int counter = 0;

#include "../../include/cell.h"

BOOST_AUTO_TEST_CASE(test_cell_live) {
  Cell a = Cell(Bool(true));
  Cell b = Cell(Bool(false));
  BOOST_REQUIRE(!a.live(4).status());
  BOOST_REQUIRE(a.live(2).status());
  BOOST_REQUIRE(a.live(3).status());
  BOOST_REQUIRE(!a.live(0).status());
  BOOST_REQUIRE(b.live(3).status());
  BOOST_REQUIRE(!b.live(1).status());
  BOOST_REQUIRE(!b.live(2).status());
}
