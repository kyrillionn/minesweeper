#include "point.hpp"
#include "board.hpp"
#include "random.hpp"

Point Point::generateRandomPoint() {
    int x = Random::get(0, Board::getBoardSize() - 1);
    int y = Random::get(0, Board::getBoardSize() - 1);

    return Point{x, y};
}

bool operator==(const Point& p1, const Point& p2) {
    return (p1.getX() == p2.getX()) && (p1.getY() == p2.getY());
}

bool Point::isValid() const {
    return (m_x >= 0 && m_x < Board::getBoardSize()) && (m_y >= 0 && m_y < Board::getBoardSize());
}

Point Point::getAdjacentPoint(const Direction& dir) const {
    switch (dir.getType()) {
        case Direction::up: return Point{m_x - 1, m_y};
        case Direction::up_left: return Point{m_x - 1, m_y - 1};
        case Direction::up_right: return Point{m_x - 1, m_y + 1};
        case Direction::left: return Point{m_x, m_y - 1};
        case Direction::right: return Point{m_x, m_y + 1};
        case Direction::down: return Point{m_x + 1, m_y};
        case Direction::down_left: return Point{m_x + 1, m_y - 1};
        case Direction::down_right: return Point{m_x + 1, m_y + 1};
        default: return *this;
    }

    return *this;
}
