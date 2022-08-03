#include <raylib.h>
#include "Game.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialise the window
    const int screenWidth = 800;
    const int screenHeight = 600;

    Game game{screenWidth, screenHeight, 60, "Snake"};


    while (!game.GameShouldClose())
    {
        game.Tick();
    }

    return 0;
}