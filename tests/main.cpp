#include "../include/config.h"
#include "../include/game.h"

int main()
{

#ifdef TESTING
    test();
#else
    Game g = Game("");

#endif
}