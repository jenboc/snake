#pragma once
#include "Vec2.h"

namespace settings
{
    // Window Settings
    constexpr int screenWidth = 920;
    constexpr int screenHeight = 690;
    constexpr int fps = 60;
    constexpr int titleSize = 40;
    constexpr int textSize = 30;
    constexpr Color textColour = LIGHTGRAY;

    // Board Settings
    constexpr int cellSize = 23;
    constexpr int padding = 2;
    constexpr Vec2<int> boardPos{0, 0};
    constexpr Vec2<int> boardDimensions{screenWidth/cellSize, screenHeight/cellSize};

    // Player Settings
    constexpr Vec2<int> playerStartPos{20, 20};
    constexpr int movePerSecond = 3;
    constexpr Color playerColour = RED;

    // Food Settings
    constexpr Color foodColour = GREEN;
}