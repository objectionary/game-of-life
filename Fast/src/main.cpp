// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../include/arg_parse.h"
#include "../include/field.h"
#include "../include/game.h"
#include "../include/grid.h"
#include "../include/repeats.h"
#include "../include/size.h"

using std::pair;
using std::string;
using std::vector;

const int DEFAULT_VALUE = 1000;

using boost::program_options::options_description;
using boost::program_options::parse_command_line;
using boost::program_options::value;
using boost::program_options::variables_map;

int main(int ac, char *av[]) {  // NOLINT

  int opt;
  options_description desc("Allowed options");
  desc.add_options()("help", "produce help message")("batch", value<int>(),
    "if set, program runs automatically and you should state the number of "
    "cycles")("sleep", value<int>(&opt)->default_value(DEFAULT_VALUE),
    "the number of milliseconds to wait before new generation "
    "generated, default value is 1000")("size", value<string>(),
    "the size of the grid, you can state this value by passing NxM where N "
    "the number of rows, M the number of columns, for example --size 20x30")(
    "put", value<vector<string>>(),
    "initial alive cells, you can type many cells by passing NxM where N the "
    "number of row and M the number of column, for example --put 3x7 --put "
    "5x4");

  variables_map varMap;
  store(parse_command_line(ac, av, desc), varMap);
  notify(varMap);

  if (varMap.count("help") > 0) {
    cout << desc << "\n";
    return 0;
  }

  const pair<int, int> parseSize = Parse::get_size(varMap["size"].as<string>());
  const vector<pair<int, int>> put = Parse::get_alive(
    varMap["put"].as<vector<string>>(), parseSize.first, parseSize.second);

  Size size = Size(parseSize.first, parseSize.second);
  Field field = Field(size);
  field.read_and_set(put);
  if (varMap["sleep"].as<int>() < 0) {
    cout << "Incorrect sleep option value" << "\n";
    exit(0);  // NOLINT(concurrency-mt-unsafe)
  }

  if (varMap.count("batch") > 0) {
    if (varMap["batch"].as<int>() < 0) {
      cout << "Incorrect batch option value" << "\n";
      exit(0);  // NOLINT(concurrency-mt-unsafe)
    }
    const Game game = Game(Grid(size, field),
      Repeats(varMap["batch"].as<int>()), varMap["sleep"].as<int>());
  } else {
    const Game game = Game(Grid(size, field));
  }
}
