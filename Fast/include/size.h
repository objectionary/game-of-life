// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef LIFE_SIZE_H
#define LIFE_SIZE_H
#include "config.h"

class Size {
public:
  int n;
  int m;
  Size() {};
  Size(int byX, int byY);
};

#endif  // LIFE_SIZE_H
