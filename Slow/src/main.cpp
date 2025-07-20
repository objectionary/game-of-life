// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include <unistd.h>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>
#include <iostream>

#include "../include/field.h"
#include "../include/objects.h"
#include "../include/parse.h"

using boost::program_options::options_description;
using boost::program_options::parse_command_line;
using boost::program_options::value;
using boost::program_options::variables_map;
using std::cin;
using std::cout;

const int MUL = 1000;

namespace {

int counter = 0;

void sleep(int value) {
  const unsigned int microsecond = MUL * value;
  usleep(microsecond);
}

void rec(Int depth, Int max, Bool flag, Field cur, Parse parse) {
  cout << "\033[2J\033[1;1H";
  if (Less(max, depth).get()) {
    return;
  }
  cur.print();
  const Field next = cur.live();
  if (flag.get()) {
    cout << R"(If you want to play more press "n", else "q".)" << "\n";
    string str;
    cin >> str;
    if (str != "n") {
      return;
    }
    rec(depth, max, Bool(true), next, parse);
  } else {
    sleep(parse.opts()["sleep"].as<int>());  // NOLINT(concurrency-mt-unsafe)
    rec(Add(depth, Int(1)).get(), max, Bool(false), next, parse);
  }
}

}  // namespace

const int def_val = 1000;
int main(int number, char *chars[]) {
  int opt;
  options_description desc("Allowed options");
  desc.add_options()("help", "produce help message")("batch", value<int>(),
    "if set, program runs automatically and you should state the number of "
    "cycles")("sleep", value<int>(&opt)->default_value(def_val),
    "the number of milliseconds to wait before new generation "
    "generated, default value is 1000")("size", value<string>(),
    "the size of the grid, you can state this value by passing NxM where N "
    "the number of rows, M the number of columns, for example --size 20x30")(
    "put", value<vector<string>>(),
    "initial alive cells, you can type many cells by passing NxM where N the "
    "number of row and M the number of column, for example --put 3x7 --put "
    "5x4");
  variables_map varMap;
  store(parse_command_line(number, chars, desc), varMap);
  notify(varMap);
  Parse parse = Parse(varMap);
  parse.build();
  Field clear = Field(Int(parse.length()), Int(parse.width()));
  const Field field = clear.rec_add(clear, parse.grid(), Int(0));
  if (varMap.count("batch") > 0) {
    rec(Int(0), Int(varMap["batch"].as<int>()), Bool(false), field, parse);
  } else {
    rec(Int(0), Int(0), Bool(true), field, parse);
  }
  cout << "The total number of created objects is: " << counter << "\n";
}
