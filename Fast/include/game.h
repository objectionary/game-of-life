// SPDX-FileCopyrightText: Copyright (c) 2022-2025 Anton Shatokhin
// SPDX-License-Identifier: MIT

#ifndef LIFE_GAME_H
#define LIFE_GAME_H

#include "grid.h"
#include "repeats.h"
class Game {
public:
  Game(Grid gr, Repeats rep, int time);
  Game(Grid gr);
};

#endif  // LIFE_GAME_H
