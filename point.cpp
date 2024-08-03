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
