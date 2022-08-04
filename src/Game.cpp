#include <raylib.h> 
#include <assert.h> 
#include <string> 
#include "Game.h"
#include "Settings.h"

Game::Game(int width, int height, int fps, std::string title) 
    :
    currentState(mainMenu),
    board(settings::boardPos,
          settings::boardDimensions,
          settings::cellSize,
          settings::padding),
    player(settings::playerStartPos,
           board),
    food(player, board),
    score(0)
{ 
    // Set up window 
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
    
    switch(currentState) 
    {
    case mainMenu:
        DrawMenu("Snake", "\nPress SPACE to start\nUse WASD to move");
        break;
    case mainGame: 
        board.Draw();
        food.Draw();
        player.Draw();
        break;
    case deathScreen:
        std::string text = "\nYour Score: " + std::to_string(score) + "\nPress SPACE to return to menu";
        DrawMenu("You Died!", text);
        break;
    }
    
}

void Game::DrawMenu(std::string title, std::string text) 
{
    DrawText(title.c_str(), settings::padding, settings::padding, settings::titleSize, settings::textColour);
    DrawText(text.c_str(), settings::padding, settings::padding, settings::textSize, settings::textColour);
}

void Game::Update() 
{
    switch(currentState)
    {
    case mainMenu:
        if (IsKeyPressed(KEY_SPACE))
        {
            score = 0;
            currentState = mainGame;
        }
        break;
    case mainGame:
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
            score++;
        }

        if (!player.isAlive)
            currentState = deathScreen;

        break;
    case deathScreen:
        if (IsKeyPressed(KEY_SPACE)) 
        {  
            player.Reset();
            food.GenerateNewPos();
            currentState = mainMenu;
        }
        break;
    }
}