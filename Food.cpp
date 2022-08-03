#include "Food.h"
#include "Vec2.h"
#include "Settings.h"
#include <chrono>

Food::Food(const Player& ply, const Board& board) 
    :
    player(ply),
    board(board)
{
    GenerateNewPos();
}

bool Food::IsEaten() 
{
    Vec2<int> plyrPos = player.GetHead();
    bool eaten = (plyrPos == pos);

    if (eaten)
        GenerateNewPos();

    return eaten;
}

void Food::GenerateNewPos() 
{
    int maxX = settings::boardDimensions.GetX();
    int maxY = settings::boardDimensions.GetY();

    // Random Seed - based on unix time 
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    int unix = ms.count();
    SetRandomSeed(unix);

    int x = GetRandomValue(0, maxX);
    int y = GetRandomValue(0, maxY);

    pos = Vec2<int>{x,y};
}

void Food::Draw() 
{
    board.DrawCell(pos, settings::foodColour);
}