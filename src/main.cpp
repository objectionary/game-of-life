#pragma once
#include "config.cpp"
#include "game.cpp"
#include "../Tests/test.cpp"

int main()
{
   
   #ifdef TESTING
    test();
    #else
    Game g = Game("");
    
 #endif
}