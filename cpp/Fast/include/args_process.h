// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef LIFE_PROCESS_H
#define LIFE_PROCESS_H

#include <bits/stdc++.h>

#include <string>
#include <utility>

using std::pair;
using std::string;

class Process {
public:
  Process() {};
  static pair<string, string> split(string const &str);
  static pair<int, int> convert(pair<string, string> const &param);
};
#endif  // LIFE_PROCESS_H
