#include "Player.h"
#include <raylib.h>
#include "Vec2.h"
#include "Board.h"
#include "Settings.h"


Player::Player(Vec2<double> startPos, const Board& board) 
    :
    isAlive(true),
    dir('d'),
    sinceLastMove(0),
    board(board)
{  
    body.resize(1);
    body[0] = startPos;
}

void Player::Update()
{
    sinceLastMove++;

    if (sinceLastMove < (settings::fps / settings::movePerSecond)) 
    {
        return; 
    }
    
    sinceLastMove = 0;

    // Move
    Vec2<double> offset{0,0};
    switch(dir) 
    {
    case 'w':
        offset = Vec2<double>{0,-1};
        break;
    case 'a':
        offset = Vec2<double>{-1,0};
        break;
    case 's':
        offset = Vec2<double>{0,1};
        break;
    case 'd':
        offset = Vec2<double>{1,0};
        break;
    };

    for (int i = 0; i < body.size(); i++) 
    {
        body[i] += offset; 
        if (body[i].GetX() > settings::boardDimensions.GetX())
        {
            body[i].SetX(0);
        }
        else if (body[i].GetX() < 0)
        {
            body[i].SetX(settings::boardDimensions.GetX());
        }

        if (body[i].GetY() > settings::boardDimensions.GetY())
        {
            body[i].SetY(settings::boardDimensions.GetY());
        }
        else if (body[i].GetY() < 0)
        {
            body[i].SetY(settings::boardDimensions.GetY());
        }
    }
}

void Player::Draw() 
{
    for (int i = 0; i < body.size(); i++) 
    {
        board.DrawCell(Vec2<int>{(int)body[i].GetX(), (int)body[i].GetY()}, RED);
    }
}

void Player::ChangeDir(char direction)
{
    if ((dir == 'a' && direction == 'd') ||
        (dir == 'd' && direction == 'a') ||
        (dir == 'w' && direction == 's') ||
        (dir == 's' && direction == 'w'))
        return;
        
    dir = direction;
}