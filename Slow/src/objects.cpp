// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/objects.h"

extern int counter;

Bool::Bool(bool val) : val(val) { counter++; }

bool Bool::get() const { return val; }

Int::Int(int val) : val(val) { counter++; }

int Int::get() const { return val; }

Less::Less(Int lhs, Int rhs) : left(lhs), right(rhs) { counter++; }

bool Less::get() { return left.get() < right.get(); }

Add::Add(Int lhs, Int rhs) : left(lhs), right(rhs) { counter++; }

int Add::get() { return left.get() + right.get(); }

Sub::Sub(Int lhs, Int rhs) : left(lhs), right(rhs) { counter++; }

int Sub::get() { return left.get() - right.get(); }

And::And(Bool lhs, Bool rhs) : left(lhs), right(rhs) { counter++; }

Bool And::get() { return {left.get() && right.get()}; }

Or::Or(Bool lhs, Bool rhs) : left(lhs), right(rhs) { counter++; }

Bool Or::get() { return {left.get() || right.get()}; }

Eq::Eq(Int lhs, Int rhs) : left(lhs), right(rhs) { counter++; }

Bool Eq::get() { return {left.get() == right.get()}; }

Not::Not(Bool val) : val(val) { counter++; }

Bool Not::get() { return {!val.get()}; }
