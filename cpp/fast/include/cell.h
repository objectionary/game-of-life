// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef LIFE_CELL_H
#define LIFE_CELL_H

class Cell {
private:
  bool curState = false;
  bool newState = false;

public:
  void changeNewState(bool val);

  void changeCurState();

  void setState(bool val);

  bool getCurState() const;
};

#endif  // LIFE_CELL_H
