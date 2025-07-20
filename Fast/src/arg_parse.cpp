// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/arg_parse.h"

#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

#include "../include/args_process.h"
#include "../include/args_valid.h"

using std::cout;
using std::exit;
using std::pair;

const int SIZE = 20;

pair<int, int> Parse::get_size(string const &str) {
  if (str.empty()) {
    return {SIZE, SIZE};
  }
  if (Valid::is_valid(str)) {
    return Process::convert(Process::split(str));
  }
  cout << "Incorrect arguments in size option" << "\n";
  exit(0);  // NOLINT(concurrency-mt-unsafe)
}

vector<pair<int, int>> Parse::get_alive(
  vector<string> const &field, int byN, int byM) {
  vector<pair<int, int>> res;
  for (auto const &str : field) {
    const Valid valid = Valid();
    if (Valid::is_valid(str)) {
      const pair<int, int> processes = Process::convert(Process::split(str));
      if (processes.first <= 0 || processes.first > byN ||
          processes.second <= 0 || processes.second > byM) {
        cout << "You entered cells out of range of the grid " << str << "\n";
        exit(0);  // NOLINT(concurrency-mt-unsafe)
      }
      res.emplace_back(processes);
    } else {
      cout << "You entered incorrect arguments in put option" << "\n";
      exit(0);  // NOLINT(concurrency-mt-unsafe)
    }
  }
  return res;
}
