#pragma once

class Direction {
public:
    enum Type {
        up,
        up_right,
        up_left,
        left,
        right,
        down,
        down_right,
        down_left,
        max_directions
    };

    Direction(Type dir) : m_direction {dir} {}

    Type getType() const { return m_direction; }

private:
    Type m_direction;
};
