#pragma once 
#include <vector> 
#include "Vec2.h"
#include "Board.h"

class Player 
{
public:
    Player(Vec2<int> startPos, const Board& board);
    bool isAlive; 
    void Reset(); 
    void Update();
    void Draw();
    void ExtendBody(int n);
    void ChangeDir(char direction);
    Vec2<int> GetHead() const;
private:
    Vec2<int> startPos; 
    Vec2<int> dir;
    int sinceLastMove;
    const Board& board;
    std::vector<Vec2<int>> body; 
};