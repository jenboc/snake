#include <raylib.h> 
#include <assert.h> 

#include "Game.h"
#include "Settings.h"

Game::Game(int width, int height, int fps, std::string title) 
    :
    board(settings::boardPos,
          settings::boardDimensions,
          settings::cellSize,
          settings::padding),
    player(settings::playerStartPos,
           board),
    food(player, board)
{
    assert(!GetWindowHandle()); // If triggers: window already opened
    SetTargetFPS(fps);
    InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept
{
    assert(GetWindowHandle()); // If triggers: window already closed
    CloseWindow();
}

bool Game::GameShouldClose() const
{
    return WindowShouldClose();
}

void Game::Tick()
{
    Update();
    BeginDrawing();
    Draw();
    EndDrawing();
}

void Game::Draw() 
{
    ClearBackground(BLACK);
    board.Draw();
    food.Draw();
    player.Draw();
}

void Game::Update() 
{
    if (IsKeyPressed(KEY_W))
    {
        player.ChangeDir('w');
    }
    else if (IsKeyPressed(KEY_A))
    {
        player.ChangeDir('a');
    }
    else if (IsKeyPressed(KEY_S))
    {
        player.ChangeDir('s');
    }
    else if (IsKeyPressed(KEY_D))
    {
        player.ChangeDir('d');
    }

    player.Update();

    if (food.IsEaten())
    {
        player.ExtendBody(1); 
    }
}