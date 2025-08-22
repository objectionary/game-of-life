// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef _OOP_OBJECTS_H_
#define _OOP_OBJECTS_H_

class Bool {
private:
  bool val;

public:
  Bool() : Bool(false) {}
  Bool(bool val);
  bool get() const;
};

class Int {
private:
  int val;

public:
  Int() : Int(0) {};
  Int(int val);
  int get() const;
};

class Less {
private:
  Int left;
  Int right;

public:
  Less(Int lhs, Int rhs);
  bool get();
};

class Add {
private:
  Int left;
  Int right;

public:
  Add(Int lhs, Int rhs);
  int get();
};

class Sub {
private:
  Int left;
  Int right;

public:
  Sub(Int lhs, Int rhs);
  int get();
};

class And {
private:
  Bool left;
  Bool right;

public:
  And(Bool lhs, Bool rhs);
  Bool get();
};

class Or {
private:
  Bool left;
  Bool right;

public:
  Or(Bool lhs, Bool rhs);
  Bool get();
};

class Eq {
private:
  Int left;
  Int right;

public:
  Eq(Int lhs, Int rhs);
  Bool get();
};

class Not {
private:
  Bool val;

public:
  Not(Bool val);
  Bool get();
};

#endif
