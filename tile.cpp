#include "tile.hpp"

std::ostream& operator<<(std::ostream& out, const Tile& t) {
    if (t.isHidden())
        return out << "X";

    if (t.isMine())
        return out << "*";

    if (t.isEmpty())
        return out << " ";

    return out << t.getNum();
}
