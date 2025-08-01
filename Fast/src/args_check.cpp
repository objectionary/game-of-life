// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/args_check.h"

#include <cctype>
#include <string>
#include <utility>

using std::isdigit;
using std::pair;
using std::string;

bool Check::has_x(string const &str) {
  return str.find('x') < str.length() - 1 && str.find('x') > 0;
}

bool Check::is_d(pair<string, string> const &param) {
  for (char const &coord : param.first) {
    if (isdigit(coord) == 0) {
      return false;
    }
  }
  for (char const &coord : param.second) {
    if (isdigit(coord) == 0) {
      return false;
    }
  }
  return stoi(param.first) > 0 && stoi(param.second) > 0;
}
