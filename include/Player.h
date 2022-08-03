#pragma once 
#include <vector> 
#include "Vec2.h"
#include "Board.h"

class Player 
{
public:
    Player(Vec2<double> startPos, const Board& board);
    bool isAlive; 
    void Update();
    void Draw();
    void ChangeDir(char direction);
private:
    char dir;
    int sinceLastMove;
    const Board& board;
    std::vector<Vec2<double>> body; 
};