// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef _OOP_FIELD_H_
#define _OOP_FIELD_H_

#include <bits/stdc++.h>

#include "cell.h"

using namespace std;

class Field {
private:
  vector<vector<Cell>> grid;
  void rec_line_print(Int depth);
  vector<vector<Cell>> rec_create_vector(
    Int n, Int m, Int cur_n, Int cur_m, vector<vector<Cell>> res);
  void rec_grid_print(Int x, Int y);

public:
  Field(Int n, Int m) : Field(make_grid(n, m)) {}
  Field(vector<vector<Cell>> g);

  vector<vector<Cell>> field();  // getters

  Field rec_add(Field cur, vector<pair<int, int>> s, Int pos);
  Field rec_live(Int x, Int y, Field cur);

  vector<vector<Cell>> make_grid(Int n, Int m);
  Field live();
  Field with(Int x, Int y, Cell a);
  void print();  // next_gen makers
  Int count(Int x, Int y);
};

#endif  //_OOP_FIELD_H_
