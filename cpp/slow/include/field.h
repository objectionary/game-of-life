// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef _OOP_FIELD_H_
#define _OOP_FIELD_H_

#include <utility>
#include <vector>

#include "cell.h"

using std::pair;
using std::vector;

class Field {
private:
  vector<vector<Cell>> grid;
  void rec_line_print(Int depth);
  vector<vector<Cell>> rec_create_vector(
    Int lhs, Int rhs, Int currLhs, Int currRhs, vector<vector<Cell>> res);
  void rec_grid_print(Int lhs, Int rhs);

public:
  Field(Int n, Int m) : Field(make_grid(n, m)) {}
  Field(vector<vector<Cell>> g);

  vector<vector<Cell>> field();  // getters

  Field rec_add(Field cur, vector<pair<int, int>> rec, Int pos);
  Field rec_live(Int x, Int y, Field cur);

  vector<vector<Cell>> make_grid(Int lhs, Int rhs);
  Field live();
  Field with(Int numberX, Int numberY, Cell cell);
  void print();  // next_gen makers
  Int count(Int x, Int y);
};

#endif  //_OOP_FIELD_H_
