// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/grid.h"

#include <iostream>

#include "../include/field.h"
#include "../include/size.h"

using std::cout;

const int ADD = 5;

Grid::Grid(Size &size, Field &field) : s(size), g(field) {}

void Grid::printGrid() {
  for (int i = 0; i < s.m * 2 + ADD; ++i) {
    cout << "-";
  }
  cout << "\n";
  for (int i = 0; i < s.n; ++i) {
    cout << "|  ";
    for (int j = 0; j < s.m; ++j) {
      if (g.f[i][j].getCurState()) {
        cout << "o ";
      } else {
        cout << ". ";
      }
    }
    cout << " |\n";
  }
  for (int i = 0; i < s.m * 2 + ADD; ++i) {
    cout << "-";
  }
  cout << "\n";
}

void Grid::nextGen() {
  for (int i = 0; i < s.n; ++i) {
    for (int j = 0; j < s.m; ++j) {
      const int cnt = g.count(i, j, s);
      if (g.f[i][j].getCurState()) {
        g.f[i][j].changeNewState(cnt == 2 || cnt == 3);
      } else {
        g.f[i][j].changeNewState(cnt == 3);
      }
    }
  }

  for (int i = 0; i < s.n; ++i) {
    for (int j = 0; j < s.m; ++j) {
      g.f[i][j].changeCurState();
    }
  }
}
