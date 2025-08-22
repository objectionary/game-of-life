// SPDX-FileCopyrightText: Copyright (c) 2022 Anton Shatokhin
// SPDX-License-Identifier: MIT

#include "../include/game.h"

#include <unistd.h>

#include <iostream>
#include <string>

#include "../include/grid.h"
#include "../include/repeats.h"

using std::cin;
using std::cout;
using std::string;

const int MULT = 1000;

namespace {
void sleep(int time) {
  const unsigned int microsecond = time * MULT;
  usleep(microsecond);
}
}  // namespace

Game::Game(Grid grid, Repeats rep, int time) {
  for (int i = 0; i <= rep.rep; i++) {
    cout << "\033[2J\033[1;1H";
    grid.printGrid();
    cout << "This is iteratrion number " << i << "\n";
    sleep(time);  // NOLINT(concurrency-mt-unsafe)
    grid.nextGen();
  }
}

Game::Game(Grid grid) {
  while (true) {
    cout << "\033[2J\033[1;1H";
    grid.printGrid();
    cout << R"(If you want to carry on, type "n", else type "q")" << "\n";
    string str;
    cin >> str;
    if (str == "n") {
      grid.nextGen();
    } else {
      return;
    }
  }
}
