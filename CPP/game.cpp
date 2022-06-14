
#include "grid.cpp"
#include "config.cpp"
#pragma once

class Game: public Grid {

public:
    Game() {
        Set();
        while (true) {
            printGrid();
            wprintf(L"If you want to see next step, type \"n\", else type \"q\"\n");
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
};