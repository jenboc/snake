#include "Player.h"
#include <raylib.h>
#include "Vec2.h"
#include "Board.h"
#include "Settings.h"

Player::Player(Vec2<int> startPos, const Board& board) 
    :
    isAlive(true),
    dir(0,0),
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
    for (int i = 0; i < body.size(); i++) 
    {
        body[i] += dir; 
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
        board.DrawCell(Vec2<int>{body[i].GetX(), body[i].GetY()}, settings::playerColour);
    }
}

void Player::ExtendBody(int n) 
{
    if (n <= 0) 
        return; 

    int lastIndex = body.size() - 1; 
    body.resize(body.size() + n);

    Vec2<int> newCellPos = body[lastIndex] - dir;
    body[lastIndex+1] = newCellPos;

    ExtendBody(n-1); 
}

void Player::ChangeDir(char dirKey)
{
    switch(dirKey) 
    {
    case 'w':
        dir = Vec2<int>{0,-1};
        break;
    case 'a':
        dir = Vec2<int>{-1,0};
        break;
    case 's':
        dir = Vec2<int>{0,1};
        break;
    case 'd':
        dir = Vec2<int>{1,0};
        break;
    };
}

Vec2<int> Player::GetHead() const 
{
    return body[0];
}