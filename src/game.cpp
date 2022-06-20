
#include "../include/game.h"
    Game:: Game(string filename) : Grid(filename)
    {
        Set("");
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