//
// Created by eciuc on 4/16/2024.
//

#ifndef OOP_COLOREDTRIANGLE_H
#define OOP_COLOREDTRIANGLE_H

#include "Triangle.h"
#include <SFML/Graphics.hpp>

class Triangle;

class ColoredTriangle {
public:
    const Triangle* triangle= nullptr;
    sf::Color color;
};


#endif //OOP_COLOREDTRIANGLE_H
