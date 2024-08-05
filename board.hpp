#pragma once

#include "tile.hpp"
#include "point.hpp"

class Board {
public:
    Board() { randomize(); }

    void randomize();
    static int getBoardSize() { return m_boardSize; };
    static int getMaxMines() { return m_maxMines; };
    int revealTiles(const Point& p);

    friend std::ostream& operator<<(std::ostream& out, const Board& b);

private:
    static const int m_boardSize = 8;
    static const int m_maxMines = 10;

    Tile m_board[m_boardSize][m_boardSize];
};
