#pragma once
#include "../src/config.cpp"
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