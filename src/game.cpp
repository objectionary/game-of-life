
#include "../include/game.h"
#include <unistd.h>
Game::Game() {
  Set();
  while (true) {
    printGrid();
    cout << "If you want to see next step, type \"n\", else type \"q\"\n";
    string s;
    cin >> s;
    if (s == "n") {
      cout << "\033[2J\033[1;1H";
      nextGen();
    } else {
      exit(0);
    }
  }
}
