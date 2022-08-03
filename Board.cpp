#include "Board.h"
#include <raylib.h>
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
Board::Board(int x, int y, int width_in, int height_in, int cellSize_in, int padding_in) 
    : 
    screenX(x),
    screenY(y),
    width(width_in), 
    height(height_in),
    cellSize(cellSize_in),
    padding(padding_in)
{
    assert(width > 0 && height > 0);
    assert(cellSize > 0);
    cells.resize(width*height);
}

void Board::SetCell(int x, int y, Color c) 
{
    assert(x >= 0 && y >= 0 && x < width && y < height);
    int index = (width * y) + x;
    cells[index].SetColour(c);
}

void Board::DrawCell(int x, int y) const 
{
    assert(x >= 0 && x < width && y >= 0 && y < height);
    int index = (width * y) + x;
    Color c = cells[index].GetColour();
    DrawRectangle(screenX + x * cellSize + padding,
                screenY + y * cellSize + padding,
                cellSize - padding,
                cellSize - padding,
                c);
}

void Board::Draw() const 
{
    for (int iY = 0; iY < height; iY++) 
    {
        for (int iX = 0; iX < width; iX++)
        {
            DrawCell(iX, iY);
        }
    }
}