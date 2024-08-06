#include "board.hpp"
#include "point.hpp"
#include "direction.hpp"

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

void Board::setNumbers(const Point& adjPoint, Tile& currentTile) {
    if (adjPoint.isValid()) {
        Tile& adjTile = m_board[adjPoint.getX()][adjPoint.getY()];

        if (adjTile.isMine() && !currentTile.isMine())
            currentTile.setNum(currentTile.getNum() + 1);
    }
}

void Board::findAdjacentEmptyTiles(const Point& adjPoint, Tile& currentTile) {
    while (adjPoint.isValid()) {
        Tile& adjTile = m_board[adjPoint.getX()][adjPoint.getY()];

        //help
    }
}

// there's definitely a better way to do this function (probably without function pointers)
// but idk how to do it
void Board::boardLoop(void (Board::*tileFcn)(const Point&, Tile&)) {
    for (int i = 0; i < m_boardSize; ++i) {
        for (int j = 0; j < m_boardSize; ++j) {
            Point currentPoint {i, j};
            Tile& currentTile = m_board[i][j];

            for (int dir = 0; dir < Direction::max_directions; ++dir) {
                Point adjPoint = currentPoint.getAdjacentPoint(static_cast<Direction::Type>(dir));
                
                (this->*tileFcn)(adjPoint, currentTile);
            }
        }
    }
}

int Board::revealTiles(const Point& p) {
    Tile& t = m_board[p.getX()][p.getY()];

    t.setHidden(false);

    if (t.getNum() == -1)
        return -1;
    
    if (t.getNum())
        return t.getNum();

    boardLoop(findAdjacentEmptyTiles);

    return 0;
}

void Board::unhideAll() {
    for (auto& row : m_board)
        for (auto& tile : row)
            tile.setHidden(false);
}
