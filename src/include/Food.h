#pragma once
#include "Vec2.h"
#include "Board.h"
#include "Player.h"

class Food 
{
public:
    Food(const Player& ply, const Board& board);
    void GenerateNewPos();
    bool IsEaten();
    void Draw(); 
private:
    Vec2<int> pos;
    const Player& player;
    const Board& board;
};