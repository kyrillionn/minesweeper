#include "tile.hpp"

std::ostream& operator<<(std::ostream& out, const Tile& t) {
    if (t.isBomb())
        return out << "*";

    if (t.isEmpty())
        return out << " ";

    return out << t.getNum();
}
