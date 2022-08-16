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
  Bool() : Bool(false) {}
  Bool(bool b);
  bool get() const;
};

class Int {
private:
  int val;

public:
  Int() : Int(0){};
  Int(int i);
  int get() const;
};

class Less {
private:
  Int left;
  Int right;

public:
  Less(Int l, Int r);
  bool get();
};

class Add {
private:
  Int left;
  Int right;

public:
  Add(Int l, Int r);
  int get();
};

class Sub {
private:
  Int left;
  Int right;

public:
  Sub(Int l, Int r);
  int get();
};

class And {
private:
  Bool left;
  Bool right;

public:
  And(Bool l, Bool r);
  Bool get();
};

class Or {
private:
  Bool left;
  Bool right;

public:
  Or(Bool l, Bool r);
  Bool get();
};

class Eq {
private:
  Int left;
  Int right;

public:
  Eq(Int l, Int r);
  Bool get();
};

class Not {
private:
  Bool val;

public:
  Not(Bool b);
  Bool get();
};

#endif