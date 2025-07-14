// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

extern int counter;

#include "../include/objects.h"

Bool::Bool(bool b) {
  val = b;
  counter++;
}

bool Bool::get() const { return val; }

Int::Int(int i) {
  val = i;
  counter++;
}

int Int::get() const { return val; }

Less::Less(Int l, Int r) {
  left = l;
  right = r;
  counter++;
}

bool Less::get() { return left.get() < right.get(); }

Add::Add(Int l, Int r) {
  left = l;
  right = r;
  counter++;
}

int Add::get() { return left.get() + right.get(); }

Sub::Sub(Int l, Int r) {
  left = l;
  right = r;
  counter++;
}

int Sub::get() { return left.get() - right.get(); }

And::And(Bool l, Bool r) {
  left = l;
  right = r;
  counter++;
}

Bool And::get() { return {left.get() && right.get()}; }

Or::Or(Bool l, Bool r) {
  left = l;
  right = r;
  counter++;
}

Bool Or::get() { return {left.get() || right.get()}; }

Eq::Eq(Int l, Int r) {
  left = l;
  right = r;
  counter++;
}

Bool Eq::get() { return {left.get() == right.get()}; }

Not::Not(Bool b) {
  val = b;
  counter++;
}

Bool Not::get() { return {!val.get()}; }
