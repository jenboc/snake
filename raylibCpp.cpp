#include "raylibCpp.h"
#include <raylib.h>
#include <assert.h>

void raycpp::DrawRectangle(Vec2<int> pos, Vec2<int> dimensions, Color colour)
{
    int x = pos.GetX();
    int y = pos.GetY();

    assert(x >= 0 && x < GetScreenWidth() && y >= 0 && y < GetScreenHeight());

    DrawRectangle(x, y, dimensions.GetX(), dimensions.GetY(), colour);
}