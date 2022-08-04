#include "Player.h"
#include <raylib.h>
#include "Vec2.h"
#include "Board.h"
#include "Settings.h"

Player::Player(Vec2<int> startPos, const Board& board) 
    :
    isAlive(true),
    startPos(startPos),
    dir(0,0),
    sinceLastMove(0),
    board(board)
{  
    body.resize(1);
    body[0] = {startPos.GetX(), startPos.GetY()};
}

void Player::Reset() 
{
    body.resize(1); 
    body[0] = {startPos.GetX(), startPos.GetY()}; 
    isAlive = true;
    dir = {0,0};
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
    if (isAlive)
    {
        for (int i = body.size()-1; i > 0; i--) 
        {
            body[i] = Vec2<int>{body[i-1].GetX(), body[i-1].GetY()};
        }
        body[0] += dir;
    }

    // Collision Detection 
    // Borders
    if (body[0].GetX() < 0) 
    {
        body[0].SetX(0);
        isAlive = false;
    }
    else if (body[0].GetX() > settings::boardDimensions.GetX())
    {
        body[0].SetX(settings::boardDimensions.GetX());
        isAlive = false; 
    }

    if (body[0].GetY() < 0)
    {
        body[0].SetY(0);
        isAlive = false;
    }
    else if (body[0].GetY() > settings::boardDimensions.GetY()) 
    {
        body[0].SetY(settings::boardDimensions.GetY());
        isAlive = false;
    }

    // Body
    for (int i = 1; i < body.size(); i++) 
    {
        if (body[i] == body[0]) 
        {
            isAlive = false;
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