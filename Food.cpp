#include <stdlib.h>
#include "Food.h"
#include "Vec2.h"
#include "Settings.h"

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

    int x = std::rand() % maxX;
    int y = std::rand() % maxY;

    pos = Vec2<int>{x,y};
}

void Food::Draw() 
{
    board.DrawCell(pos, settings::foodColour);
}