#pragma once

#include <iostream>

class Tile {
public:
    Tile(int num) : m_numOfBombs {num} {}

    Tile() = default;

    int getNum() const { return m_numOfBombs; }
    void setNum(int num) { m_numOfBombs = num; }
    bool isBomb() const { return m_numOfBombs == -1; } // -1 will indicate that a tile contains a bomb.
    bool isEmpty() const { return m_numOfBombs == 0; }

    friend std::ostream& operator<<(std::ostream& out, const Tile& t);

private:
    int m_numOfBombs = 0;
};
