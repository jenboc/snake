#pragma once
#include <raylib.h>
#include <vector>

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
    Board(int x, int y, int width_in, int height_in, int cellSize_in, int padding_in);
    void SetCell(int x, int y, Color c);
    void DrawCell(int x, int y) const;
    void Draw() const;

private: 
    std::vector<Cell> cells; 
    int screenX;
    int screenY;
    const int width;
    const int height;
    const int cellSize;
    const int padding;
};