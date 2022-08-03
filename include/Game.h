#pragma once
#include <string>
#include "Board.h"
#include "Player.h"
#include "Food.h"

class Game 
{
public:
    Game(int width, int height, int fps, std::string title);
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    ~Game() noexcept;

    bool GameShouldClose() const;

    void Tick(); 
     
private: 
    void Draw();
    void Update();
    
    void DrawMenu(std::string title, std::string text);

    enum states
    {
        mainMenu,
        mainGame, 
        deathScreen
    };
    states currentState;

    Board board;
    Player player;
    Food food;

    int score;
};