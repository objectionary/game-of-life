// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef LIFE_PARSE_H
#define LIFE_PARSE_H

#include <string>
#include <utility>
#include <vector>
using namespace std;

class Parse {
public:
  Parse() {};
  static pair<int, int> get_size(string const& s);
  static vector<pair<int, int>> get_alive(
    vector<string> const& field, int byN, int byM);
};

#endif  // LIFE_PARSE_H
