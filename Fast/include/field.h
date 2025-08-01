// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef LIFE_FIELD_H
#define LIFE_FIELD_H

#include <utility>
#include <vector>

#include "cell.h"
#include "size.h"

using std::pair;
using std::vector;

class Field {
public:
  vector<vector<Cell>> f;
  Field() {};
  Field(Size size);
  void read_and_set(vector<pair<int, int>> const &rawField);
  int count(int byX, int byY, Size size);
};

#endif  // LIFE_FIELD_H
