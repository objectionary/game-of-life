// SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef LIFE_GRID_H
#define LIFE_GRID_H

#include "field.h"
#include "size.h"

class Grid {
public:
  Size s;
  Field g;
  Grid(Size &st, Field &ff);
  void printGrid();
  void nextGen();
};

#endif  // LIFE_GRID_H
