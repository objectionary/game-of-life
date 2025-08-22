// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/cell.h"

#include "../include/objects.h"

extern int counter;

bool Cell::status() { return state.get(); }

Cell::Cell(Bool state) : state(state) { counter++; }

Cell Cell::live(Int cnt) const {
  auto res =
    Or(And(state, Or(Eq(cnt, Int(2)).get(), Eq(cnt, Int(3)).get()).get()).get(),
      And(Not(state).get(), Eq(cnt, Int(3)).get()).get())
      .get();
  return {res};
}
