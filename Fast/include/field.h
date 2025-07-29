// SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef LIFE_FIELD_H
#define LIFE_FIELD_H

#include "cell.h"
#include "size.h"

class Field {
public:
  vector<vector<Cell>> f;
  Field(){};
  Field(Size sz);
  void read_and_set(vector<pair<int, int>> const &al);
  int count(int x, int y, Size sz);
};

#endif  // LIFE_FIELD_H
