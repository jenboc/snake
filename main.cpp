#include <raylib.h>
#include "Game.h"
#include "Settings.h"

int main(void)
{
    Game game{settings::screenWidth, settings::screenHeight, 60, "Snake"};


    while (!game.GameShouldClose())
    {
        game.Tick();
    }

    return 0;
}