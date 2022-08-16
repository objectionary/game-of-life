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

#include "../include/field.h"

const int add = 5;

extern int counter;

vector<vector<Cell>> Field::field() { return grid; }

vector<vector<Cell>> Field::rec_create_vector(
  Int n, Int m, Int cur_n, Int cur_m, vector<vector<Cell>> res) {
  if (Eq(m, cur_m).get().get()) {
    //
    counter += 5;  // NOLINT
    //
    return rec_create_vector(n, m, Int(Add(cur_n, Int(1)).get()), Int(0), res);
  }
  if (Eq(n, cur_n).get().get()) {
    //
    counter += 1;  // NOLINT
    //
    return res;
  }
  if (Eq(Int(res.size()), Int(Add(cur_n, Int(1)).get())).get().get()) {
    //
    counter += 11;  // NOLINT
    //
    res[cur_n.get()].emplace_back(Cell(Bool(false)));
    auto new_res = res;
    return rec_create_vector(
      n, m, cur_n, Int(Add(cur_m, Int(1)).get()), new_res);
  }
  //
  counter += 7;  // NOLINT
  //
  vector<Cell> a;
  a.emplace_back(Cell(Bool(false)));
  res.emplace_back(a);
  auto new_res = res;
  return rec_create_vector(n, m, cur_n, Int(Add(cur_m, Int(1)).get()), new_res);
}

vector<vector<Cell>> Field::make_grid(Int n, Int m) {
  //
  counter += 5;  // NOLINT
  //
  vector<vector<Cell>> arr;
  return rec_create_vector(Int(n), Int(m), Int(0), Int(0), arr);
}

Field Field::rec_add(Field cur, vector<pair<int, int>> s, Int pos) {
  if (Eq(pos, Int(s.size())).get().get()) {
    return cur;
  }
  pair<int, int> x = s[pos.get()];

  //
  counter += 9;  // NOLINT
  //
  return rec_add(cur.with(x.first - 1, x.second - 1, Cell(Bool(true))), s,
    Int(Add(pos, Int(1)).get()));
}

void Field::rec_line_print(Int depth) {
  Int m = Int(grid[0].size());
  if (depth.get() == m.get() * 2 + add) {
    cout << "\n";
    return;
  }
  cout << "-";
  //
  counter += 4;  // NOLINT
  //
  rec_line_print(Int(Add(depth, Int(1)).get()));
}

void Field::rec_grid_print(Int x, Int y) {
  Int n = grid.size();
  if (Or(Bool(Less(Int(n), x).get()), Eq(Int(n), x).get()).get().get()) {
    //
    counter += 6;  // NOLINT
                   //
    return;
  }

  if (Or(Less(Int(n), y).get(), Eq(Int(n), y).get()).get().get()) {
    //
    counter += 9;  // NOLINT
                   //
    cout << " |\n";
    rec_grid_print(Int(Add(x, Int(1)).get()), Int(0));
    return;
  }

  if (Eq(y, Int(0)).get().get()) {
    //
    counter += 2;  // NOLINT
                   //
    cout << "|  ";
  }
  //
  counter += 3;  // NOLINT
  //
  if (grid[x.get()][y.get()].status()) {
    cout << "o ";
  } else {
    cout << ". ";
  }
  rec_grid_print(x, Int(Add(y, Int(1)).get()));
}

Field Field::rec_live(Int x, Int y, Field cur) {
  Int n = Int(grid.size());
  Int m = Int(grid[0].size());
  if (Eq(y, m).get().get()) {
    //
    counter += 5;  // NOLINT
                   //
    return rec_live(Int(Add(x, Int(1)).get()), Int(0), cur);
  }
  if (Eq(x, n).get().get()) {
    //
    counter += 2;  // NOLINT
                   //
    return cur;
  }

  //
  counter += 5;  // NOLINT
  //
  Cell replace = cur.field()[x.get()][y.get()].live(count(x, y));
  return rec_live(x, Int(Add(y, Int(1)).get()), cur.with(x, y, replace));
}

void Field::print() {
  rec_line_print(Int(0));
  rec_grid_print(Int(0), Int(0));
  rec_line_print(Int(0));
}

Field Field::live() {
  //
  counter++;
  //
  Field obj = Field(grid);
  return rec_live(Int(0), Int(0), obj);
}

Field Field::with(Int x, Int y, Cell a) {
  //
  counter += grid.size() * grid[0].size();
  //
  vector<vector<Cell>> next = grid;
  next[x.get()][y.get()] = a;
  return Field(next);
}

Int Field::count(Int x, Int y) {
  //
  counter += 3;  // NOLINT
  //
  Int cnt = Int(0);
  Int n = Int(grid.size());
  Int m = Int(grid[0].size());
  // counting the number of alive neighbours
  if (Less(Int(Add(x, Int(1)).get()), n).get()) {
    //
    counter += 9;  // NOLINT
                   //
    cnt = Int(Add(
      cnt, Int(static_cast<int>(grid[Add(x, Int(1)).get()][y.get()].status())))
                .get());
    if (Less(Int(0), y).get()) {
      //
      counter += 8;  // NOLINT
                     //
      cnt = Int(
        Add(cnt, Int(static_cast<int>(
                   grid[Add(x, Int(1)).get()][Sub(y, Int(1)).get()].status())))
          .get());
    }
    if (Less(y, Sub(m, Int(1)).get()).get()) {
      //
      counter += 10;  // NOLINT
                      //
      cnt = Int(
        Add(cnt, Int(static_cast<int>(
                   grid[Add(x, Int(1)).get()][Add(y, Int(1)).get()].status())))
          .get());
    }
  }
  if (Less(Int(0), x).get()) {
    //
    counter += 7;  // NOLINT
                   //
    cnt = Int(Add(
      cnt, Int(static_cast<int>(grid[Sub(x, Int(1)).get()][y.get()].status())))
                .get());

    if (Less(Int(0), y).get()) {
      //
      counter += 9;  // NOLINT
                     //
      cnt = Int(
        Add(cnt, Int(static_cast<int>(
                   grid[Sub(x, Int(1)).get()][Sub(y, Int(1)).get()].status())))
          .get());
    }
    if (Less(y, Sub(m, Int(1)).get()).get()) {
      //
      counter += 10;  // NOLINT
                      //
      cnt = Int(
        Add(cnt, Int(static_cast<int>(
                   grid[Sub(x, Int(1)).get()][Add(y, Int(1)).get()].status())))
          .get());
    }
  }
  if (Less(Int(0), y).get()) {
    //
    counter += 7;  // NOLINT
                   //
    cnt = Int(Add(
      cnt, Int(static_cast<int>(grid[x.get()][Sub(y, Int(1)).get()].status())))
                .get());
  }
  if (Less(y, Sub(m, Int(1)).get()).get()) {
    //
    counter += 8;  // NOLINT
                   //
    cnt = Int(Add(
      cnt, Int(static_cast<int>(grid[x.get()][Add(y, Int(1)).get()].status())))
                .get());
  }
  return cnt;
}