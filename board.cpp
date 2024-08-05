#include "board.hpp"
#include "point.hpp"

std::ostream& operator<<(std::ostream& out, const Board& b) {
    out << "   ";

    for (int i = 0; i < b.getBoardSize(); ++i)
        out << i << " ";

    out << "\n\n";

    for (int i = 0; i < b.getBoardSize(); ++i) {
        out << i << "  ";

        for (int j = 0; j < b.getBoardSize(); ++j)
            out << b.m_board[i][j] << " ";

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
