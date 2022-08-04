#pragma once
#include <raylib.h>
#include <vector>
#include "Vec2.h"

class Board 
{
private:
    class Cell
    {
        public:
        Cell();
        void SetColour(Color colourInput);
        void Remove();

        Color GetColour() const;

        private:
        bool bExists;
        Color colour;
    };
public:
    Board(Vec2<int> screenPos, Vec2<int> dimensions, int cellSize_in, int padding_in);
    void SetCell(Vec2<int> pos, Color c);
    void SetCells(std::vector<Vec2<int>> positions, Color c);
    void DrawCell(Vec2<int> pos) const;
    void DrawCell(Vec2<int> pos, Color c) const;
    void Draw() const;

private: 
    std::vector<Cell> cells; 
    Vec2<int> screenPos;
    const int width;
    const int height;
    const int cellSize;
    const int padding;
};