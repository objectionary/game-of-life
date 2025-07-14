// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

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
