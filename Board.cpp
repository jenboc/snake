#include "Board.h"
#include "Vec2.h"
#include <raylibCpp.h>
#include <assert.h>

// ====== Cell ======
Board::Cell::Cell()
    :
    bExists(false),
    colour(WHITE)
{}

void Board::Cell::SetColour(Color colourInput)
{
    colour = colourInput;
    bExists = true;
}

void Board::Cell::Remove()
{
    bExists = false;
}

Color Board::Cell::GetColour() const
{
    return colour;
}


// ====== Board ======
Board::Board(Vec2<int> screenPos, Vec2<int> dimensions, int cellSize_in, int padding_in) 
    : 
    screenPos(screenPos),
    width(dimensions.GetX()), 
    height(dimensions.GetY()),
    cellSize(cellSize_in),
    padding(padding_in)
{
    assert(width > 0 && height > 0);
    assert(cellSize > 0);
    cells.resize(width*height);
}

void Board::SetCell(Vec2<int> pos, Color c) 
{
    int x = pos.GetX();
    int y= pos.GetY();
    assert(x >= 0 && y >= 0 && x < width && y < height);
    int index = (width * y) + x;
    cells[index].SetColour(c);
}

void Board::DrawCell(Vec2<int> pos) const 
{
    int x = pos.GetX();
    int y = pos.GetY();

    assert(x >= 0 && x < width && y >= 0 && y < height);

    int index = y * width + x;
    Color c = cells[index].GetColour();

    Vec2<int> topLeft = screenPos + padding + (pos * cellSize);
    raycpp::DrawRectangle(topLeft, Vec2<int>{cellSize, cellSize} - padding, c);
}

void Board::Draw() const 
{
    for (int iY = 0; iY < height; iY++) 
    {
        for (int iX = 0; iX < width; iX++)
        {
            Vec2<int> pos{iX, iY};
            DrawCell(pos);
        }
    }
}