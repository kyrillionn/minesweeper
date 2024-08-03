#include "tile.hpp"

std::ostream& operator<<(std::ostream& out, const Tile& t) {
    if (t.isMine())
        return out << "*";

    if (t.isEmpty())
        return out << " ";

    return out << t.getNum();
}
