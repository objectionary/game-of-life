
#include "../include/game.h"

Game::Game() : Grid() {
  Set();
  while (true) {
    printGrid();
    cout << "If you want to see next step, type \"n\", else type \"q\"\n";
    string s;
    cin >> s;
    if (s == "n") {
      system("cls");
      nextGen();
    } else {
      exit(0);
    }
  }
}