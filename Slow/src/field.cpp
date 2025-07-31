// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/field.h"

#include <iostream>
#include <utility>
#include <vector>

#include "../include/cell.h"
#include "../include/objects.h"

using std::cout;
using std::vector;

const int ADD = 5;
extern int counter;

vector<vector<Cell>> Field::field() { return grid; }

Field::Field(vector<vector<Cell>> grid) : grid(std::move(grid)) { counter++; }

vector<vector<Cell>> Field::rec_create_vector(
  Int lhs, Int rhs, Int currLhs, Int currRhs, vector<vector<Cell>> res) {
  if (Eq(rhs, currRhs).get().get()) {
    return rec_create_vector(
      lhs, rhs, Int(Add(currLhs, Int(1)).get()), Int(0), res);
  }
  if (Eq(lhs, currLhs).get().get()) {
    return res;
  }
  if (Eq(Int(static_cast<int>(res.size())), Int(Add(currLhs, Int(1)).get()))
        .get()
        .get()) {
    res[currLhs.get()].emplace_back(Bool(false));
    auto new_res = res;
    return rec_create_vector(
      lhs, rhs, currLhs, Int(Add(currRhs, Int(1)).get()), new_res);
  }
  vector<Cell> cells;
  cells.emplace_back(Bool(false));
  res.emplace_back(cells);
  auto new_res = res;
  return rec_create_vector(
    lhs, rhs, currLhs, Int(Add(currRhs, Int(1)).get()), new_res);
}

vector<vector<Cell>> Field::make_grid(Int lhs, Int rhs) {
  const vector<vector<Cell>> arr;
  return rec_create_vector(Int(lhs), Int(rhs), Int(0), Int(0), arr);
}

Field Field::rec_add(Field cur, vector<pair<int, int>> rec, Int pos) {
  if (Eq(pos, Int(static_cast<int>(rec.size()))).get().get()) {
    return cur;
  }
  const pair<int, int> record = rec[pos.get()];
  return rec_add(
    cur.with(record.first - 1, record.second - 1, Cell(Bool(true))), rec,
    Int(Add(pos, Int(1)).get()));
}

void Field::rec_line_print(Int depth) {
  const Int value = Int(static_cast<int>(grid[0].size()));
  if (depth.get() == value.get() * 2 + ADD) {
    cout << "\n";
    return;
  }
  cout << "-";
  rec_line_print(Int(Add(depth, Int(1)).get()));
}

void Field::rec_grid_print(Int lhs, Int rhs) {
  const Int value = static_cast<int>(grid.size());
  if (Or(Bool(Less(Int(value), lhs).get()), Eq(Int(value), lhs).get())
        .get()
        .get()) {
    return;
  }

  if (Or(Less(Int(value), rhs).get(), Eq(Int(value), rhs).get()).get().get()) {
    cout << " |\n";
    rec_grid_print(Int(Add(lhs, Int(1)).get()), Int(0));
    return;
  }

  if (Eq(rhs, Int(0)).get().get()) {
    cout << "|  ";
  }
  if (grid[lhs.get()][rhs.get()].status()) {
    cout << "o ";
  } else {
    cout << ". ";
  }
  rec_grid_print(lhs, Int(Add(rhs, Int(1)).get()));
}

Field Field::rec_live(Int valueX, Int valueY, Field cur) {
  const Int lhs = Int(static_cast<int>(grid.size()));
  const Int rhs = Int(static_cast<int>(grid[0].size()));
  if (Eq(valueY, rhs).get().get()) {
    return rec_live(Int(Add(valueX, Int(1)).get()), Int(0), cur);
  }
  if (Eq(valueX, lhs).get().get()) {
    return cur;
  }

  const Cell replace =
    cur.field()[valueX.get()][valueY.get()].live(count(valueX, valueY));
  return rec_live(
    valueX, Int(Add(valueY, Int(1)).get()), cur.with(valueX, valueY, replace));
}

void Field::print() {
  rec_line_print(Int(0));
  rec_grid_print(Int(0), Int(0));
  rec_line_print(Int(0));
}

Field Field::live() {
  const Field obj = Field(grid);
  return rec_live(Int(0), Int(0), obj);
}

Field Field::with(Int numberX, Int numberY, Cell cell) {
  vector<vector<Cell>> next = grid;
  next[numberX.get()][numberY.get()] = cell;
  return {next};
}

Int Field::count(Int numberX, Int numberY) {
  Int cnt = Int(0);
  const Int lhs = Int(static_cast<int>(grid.size()));
  const Int rhs = Int(static_cast<int>(grid[0].size()));

  const Int xPlus1 = Int(Add(numberX, Int(1)).get());
  const Int xMinus1 = Int(Sub(numberX, Int(1)).get());
  const Int yPlus1 = Int(Add(numberY, Int(1)).get());
  const Int yMinus1 = Int(Sub(numberY, Int(1)).get());

  if (Less(xPlus1, lhs).get()) {
    cnt = Int(Add(
      cnt, Int(static_cast<int>(grid[xPlus1.get()][numberY.get()].status())))
                .get());
    if (Less(Int(0), numberY).get()) {
      cnt = Int(Add(
        cnt, Int(static_cast<int>(grid[xPlus1.get()][yMinus1.get()].status())))
                  .get());
    }
    if (Less(numberY, Int(Sub(rhs, Int(1)).get())).get()) {
      cnt = Int(Add(
        cnt, Int(static_cast<int>(grid[xPlus1.get()][yPlus1.get()].status())))
                  .get());
    }
  }

  if (Less(Int(0), numberX).get()) {
    cnt = Int(Add(
      cnt, Int(static_cast<int>(grid[xMinus1.get()][numberY.get()].status())))
                .get());
    if (Less(Int(0), numberY).get()) {
      cnt = Int(Add(
        cnt, Int(static_cast<int>(grid[xMinus1.get()][yMinus1.get()].status())))
                  .get());
    }
    if (Less(numberY, Int(Sub(rhs, Int(1)).get())).get()) {
      cnt = Int(Add(
        cnt, Int(static_cast<int>(grid[xMinus1.get()][yPlus1.get()].status())))
                  .get());
    }
  }

  if (Less(Int(0), numberY).get()) {
    cnt = Int(Add(
      cnt, Int(static_cast<int>(grid[numberX.get()][yMinus1.get()].status())))
                .get());
  }
  if (Less(numberY, Int(Sub(rhs, Int(1)).get())).get()) {
    cnt = Int(Add(
      cnt, Int(static_cast<int>(grid[numberX.get()][yPlus1.get()].status())))
                .get());
  }

  return cnt;
}
