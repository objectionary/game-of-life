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
