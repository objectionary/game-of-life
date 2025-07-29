// SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/cell.h"
extern int counter;

bool Cell::status() { return state.get(); }

Cell::Cell(Bool st) {
  state = st;
  counter++;
}

Cell Cell::live(Int cnt) const {
  auto res =
    Or(And(state, Or(Eq(cnt, Int(2)).get(), Eq(cnt, Int(3)).get()).get()).get(),
      And(Not(state).get(), Eq(cnt, Int(3)).get()).get())
      .get();
  return {res};
}
