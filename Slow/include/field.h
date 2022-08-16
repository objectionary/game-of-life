// Copyright (c) 2022 Anton Shatokhin

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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