#include "board.hpp"
#include "point.hpp"

#include <iostream>

Point getUserInput() {
    // Doesn't do any validation because im lazy

    std::cout << "Enter a point on the board (e.g. 2,3): ";
    int x;
    char ignore;
    int y;

    std::cin >> x >> ignore >> y;

    return Point{x, y};
}

int main() {
    std::cout << "Welcome to Minesweeper!\n\n";

    Board b;

    while (true) {
        std::cout << b << "\n\n";
        Point p = getUserInput();

        int tileNum = b.revealTiles(p);

        if (tileNum == -1) {
            b.unhideAll();
            std::cout << b << "\nYou lost.";
            break;
        }
    }

    std::cout << " Thank you for playing!";

    return 0;
}
