// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
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

BOOST_AUTO_TEST_CASE(test_builds_without_batch) {
  po::options_description options;
  options.add_options()("size", po::value<string>())(
    "put", po::value<vector<string>>())("sleep", po::value<int>());
  const vector<string> args = {"--size", "3x4", "--put", "1x2", "--sleep", "1"};
  po::variables_map values;
  po::store(po::command_line_parser(args).options(options).run(), values);
  po::notify(values);
  Parse parsed(values);
  BOOST_CHECK_NO_THROW(parsed.build());
  BOOST_CHECK_EQUAL(parsed.length(), 3);
  BOOST_CHECK_EQUAL(parsed.width(), 4);
  BOOST_REQUIRE_EQUAL(parsed.grid().size(), 1);
  BOOST_CHECK_EQUAL(parsed.grid().front().first, 1);
  BOOST_CHECK_EQUAL(parsed.grid().front().second, 2);
  BOOST_CHECK_EQUAL(parsed.opts().count("batch"), 0);
}
