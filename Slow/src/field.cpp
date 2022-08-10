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

Field Field::rec_add(Field cur, vector<pair<int, int>> s, int pos) {
  if (pos == s.size()) {
    return cur;
  }
  pair<int, int> x = s[pos];

  //
  counter += 4;  // NOLINT
  //
  return rec_add(
    cur.with(x.first - 1, x.second - 1, Cell(Bool(true))), s, pos + 1);
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

void Field::rec_grid_print(int x, int y) {
  int n = grid.size();
  int m = grid[0].size();
  if (x >= n) {
    return;
  }

  if (y >= m) {
    cout << " |\n";
    rec_grid_print(x + 1, 0);
    return;
  }

  if (y == 0) {
    cout << "|  ";
  }

  if (grid[x][y].status()) {
    cout << "o ";
  } else {
    cout << ". ";
  }
  rec_grid_print(x, y + 1);
}

Field Field::rec_live(int x, int y, Field cur) {
  int n = grid.size();
  int m = grid[0].size();

  if (y == m) {
    return rec_live(x + 1, 0, cur);
  }
  if (x == n) {
    return cur;
  }

  //
  counter++;
  //
  Cell replace = cur.field()[x][y].live(count(x, y));

  //
  counter++;
  //
  return rec_live(x, y + 1, cur.with(x, y, replace));
}

void Field::print() {
  rec_line_print(0);
  rec_grid_print(0, 0);
  rec_line_print(0);
}

Field Field::live() {
  //
  counter++;
  //
  Field obj = Field(grid);
  return rec_live(0, 0, obj);
}

Field Field::with(int x, int y, Cell a) {
  vector<vector<Cell>> next = grid;
  next[x][y] = a;
  return Field(next);
}

int Field::count(int x, int y) {
  int cnt = 0;
  int n = grid.size();
  int m = grid[0].size();

  // counting the number of alive neighbours
  if (x + 1 < n) {
    cnt += static_cast<int>(grid[x + 1][y].status());
    if (y > 0) {
      cnt += static_cast<int>(grid[x + 1][y - 1].status());
    }
    if (y < m - 1) {
      cnt += static_cast<int>(grid[x + 1][y + 1].status());
    }
  }
  if (x > 0) {
    cnt += static_cast<int>(grid[x - 1][y].status());
    if (y > 0) {
      cnt += static_cast<int>(grid[x - 1][y - 1].status());
    }
    if (y < m - 1) {
      cnt += static_cast<int>(grid[x - 1][y + 1].status());
    }
  }
  if (y > 0) {
    cnt += static_cast<int>(grid[x][y - 1].status());
  }
  if (y < m - 1) {
    cnt += static_cast<int>(grid[x][y + 1].status());
  }
  return cnt;
}