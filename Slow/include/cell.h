// SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef _OOP_CELL_H_
#define _OOP_CELL_H_

using namespace std;
#include <bits/stdc++.h>

#include "objects.h"

class Cell {
private:
  Bool state;

public:
  Cell(Bool st);
  Cell() : Cell(Bool(false)) {}
  bool status();

  Cell live(Int cnt) const;
};

#endif  //_OOP_CELL_H_
