// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/args_process.h"

#include <cstddef>
#include <string>
#include <utility>

using std::pair;

pair<string, string> Process::split(string const &str) {
  const size_t pos = str.find('x');
  return {str.substr(0, pos), str.substr(pos + 1, str.length())};
}

pair<int, int> Process::convert(pair<string, string> const &param) {
  return {stoi(param.first), stoi(param.second)};
}
