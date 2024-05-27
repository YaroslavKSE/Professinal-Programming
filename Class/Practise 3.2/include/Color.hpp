#pragma once

class Color {
public:
    Color(int r, int g, int b);
    Color magicColor() const;

    int getR() const;
    int getG() const;
    int getB() const;

private:
    int r, g, b;
};
