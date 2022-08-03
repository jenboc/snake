#include <raylib.h> 
#include <assert.h> 

#include "Game.h"
#include "Settings.h"

Game::Game(int width, int height, int fps, std::string title) 
    :
    board(settings::boardPos,
          settings::boardDimensions,
          settings::cellSize,
          settings::padding)
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
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}

void Game::Draw() 
{
    ClearBackground(BLACK);
    board.Draw();
}

void Game::Update() 
{

}