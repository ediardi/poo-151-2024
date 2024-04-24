//
// Created by eciuc on 4/16/2024.
//

#ifndef OOP_COLOREDTRIANGLE_H
#define OOP_COLOREDTRIANGLE_H

#include "Triangle.h"
#include <SFML/Graphics.hpp>

class Triangle;

class ColoredTriangle {
private:
    const Triangle triangle;
    sf::Color color;
public:
    ColoredTriangle(const Triangle& triangle1,sf::Color color1);
    void set_color(sf::Color new_color);
    [[nodiscard]] Triangle get_triangle() const;
    [[nodiscard]] sf::Color get_color() const;
};


#endif //OOP_COLOREDTRIANGLE_H
