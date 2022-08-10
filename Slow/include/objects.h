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

#ifndef _OOP_OBJECTS_H_
#define _OOP_OBJECTS_H_

#include <bits/stdc++.h>
using namespace std;
class Bool {
private:
  bool val;

public:
  Bool(bool b) : val(b) {}
  bool get() const;
};

class Int {
private:
  int val;

public:
  Int(int i) : val(i) {}
  int get() const;
};

class Less {
private:
  Int left;
  Int right;

public:
  Less(Int l, Int r) : left(l), right(r) {}
  bool get();
};

class Add {
private:
  Int left;
  Int right;

public:
  Add(Int l, Int r) : left(l), right(r) {}
  int get();
};

class Sub {
private:
  Int left;
  Int right;

public:
  Sub(Int l, Int r) : left(l), right(r) {}
  int get();
};

class And {
private:
  Bool left;
  Bool right;

public:
  And(Bool l, Bool r) : left(l), right(r) {}
  Bool get();
};

class Or {
private:
  Bool left;
  Bool right;

public:
  Or(Bool l, Bool r) : left(l), right(r) {}
  Bool get();
};

class Eq {
private:
  Int left;
  Int right;

public:
  Eq(Int l, Int r) : left(l), right(r) {}
  Bool get();
};

class Not {
private:
  Bool val;

public:
  Not(Bool b) : val(b) {}
  Bool get();
};

class Mult {
private:
  Int a;
  Int b;

public:
  Mult(Int l, Int r) : a(l), b(r) {}
  int get();
};

#endif