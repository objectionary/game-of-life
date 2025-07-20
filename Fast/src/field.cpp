// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/field.h"

#include <utility>
#include <vector>

#include "../include/size.h"

using std::pair;
using std::vector;

Field::Field(Size size) {
  f.resize(size.n);
  for (int index = 0; index < size.n; ++index) {
    f[index].resize(size.m);
  }
}

void Field::read_and_set(vector<pair<int, int>> const &rawField) {
  for (auto const &pair : rawField) {
    const int byX = pair.first;
    const int byY = pair.second;
    f[byX - 1][byY - 1].setState(true);
  }
}

int Field::count(int byX, int byY, Size size) {
  int count = 0;

  for (int fIdx = byX - 1; fIdx <= byX + 1; ++fIdx) {
    for (int sIdx = byY - 1; sIdx <= byY + 1; ++sIdx) {
      if (fIdx < 0 || fIdx > size.n - 1 || sIdx < 0 || sIdx > size.m - 1) {
        continue;
      }
      count += static_cast<int>(f[fIdx][sIdx].getCurState());
    }
  }
  return count - static_cast<int>(f[byX][byY].getCurState());
}
