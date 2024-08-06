#pragma once

#include "tile.hpp"
#include "point.hpp"

#include <functional>

class Board {
public:
    Board() {
        randomize();
        boardLoop(setNumbers);
    }

    void randomize();
    static int getBoardSize() { return m_boardSize; };
    static int getMaxMines() { return m_maxMines; };
    void boardLoop(void (Board::*)(const Point&, Tile&));
    int revealTiles(const Point& p);
    void unhideAll();

    friend std::ostream& operator<<(std::ostream& out, const Board& b);

private:
    static const int m_boardSize = 10;
    static const int m_maxMines = 10;

    Tile m_board[m_boardSize][m_boardSize];

    void setNumbers(const Point& adjPoint, Tile& currentTile);
    void findAdjacentEmptyTiles(const Point& adjPoint, Tile& currentTile);
};
