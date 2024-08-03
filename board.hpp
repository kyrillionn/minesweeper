#pragma once

#include "tile.hpp"

class Board {
public:
    Board() { randomize(); }

    void randomize();

    friend std::ostream& operator<<(std::ostream& out, const Board& b);

private:
    static const int m_boardSize = 8;
    const int m_maxBombs = 10;

    Tile m_board[m_boardSize][m_boardSize];
};
