#include "board.hpp"

std::ostream& operator<<(std::ostream& out, const Board& b) {
    for (const auto& row : b.m_board) {
        for (const auto& t : row)
            out << t << " ";

        out << "\n";
    }

    return out;
}

void Board::randomize() {
    for (auto& i : m_board)
        i->setNum(-1);
}
