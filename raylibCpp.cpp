#include "raylibCpp.h"
#include <raylib.h>
#include <assert.h>
#include "Settings.h"

void raycpp::DrawRectangle(Vec2<int> pos, Vec2<int> dimensions, Color colour)
{
    int x = pos.GetX();
    int y = pos.GetY();

    assert(x >= 0 && x < settings::screenWidth && y >= 0 && y < settings::screenHeight);

    DrawRectangle(x, y, dimensions.GetX(), dimensions.GetY(), colour);
}