#pragma once

class Point {
public:
    Point(int x = 0, int y = 0) : m_x {x}, m_y {y} {}

    static Point generateRandomPoint();

    friend bool operator==(const Point& p1, const Point& p2);

    int getX() const { return m_x; }
    int getY() const { return m_y; }

private:
    int m_x = 0;
    int m_y = 0;
};
