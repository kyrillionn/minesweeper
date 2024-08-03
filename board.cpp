#include "board.hpp"
#include "point.hpp"

std::ostream& operator<<(std::ostream& out, const Board& b) {
    for (const auto& row : b.m_board) {
        for (const auto& t : row)
            out << t << " ";

        out << "\n";
    }

    return out;
}

void Board::randomize() {
    for (int mineCount = 0; mineCount < m_maxMines; ++mineCount) {
        Point randPoint = Point::generateRandomPoint();
        Tile& tile = m_board[randPoint.getX()][randPoint.getY()];

        if (tile.isEmpty())
            tile.setNum(-1);
        else
            --mineCount; // Don't increment the counter if a mine didn't get placed. 
    }
}
