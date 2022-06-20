#pragma once
#include "../include/config.h"
#include "../src/game.cpp"
#include "../Tests/test.cpp"

int main()
{

#ifdef TESTING
    test();
#else
    Game g = Game("");

#endif
}