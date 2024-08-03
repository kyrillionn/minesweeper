#pragma once

#include <iostream>

class Tile {
public:
    Tile(int num) : m_numOfMines {num} {}

    Tile() = default;

    int getNum() const { return m_numOfMines; }
    void setNum(int num) { m_numOfMines = num; }
    bool isMine() const { return m_numOfMines == -1; } // -1 will indicate that a tile contains a mine.
    bool isEmpty() const { return m_numOfMines == 0; }
    bool isHidden() const { return m_hidden; }
    void setHidden(bool h) { m_hidden = h; }

    friend std::ostream& operator<<(std::ostream& out, const Tile& t);

private:
    int m_numOfMines = 0;
    bool m_hidden = true;
};
