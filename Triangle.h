//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_TRIANGLE_H
#define OOP_TRIANGLE_H

#include "Point.h"
#include <SFML/Graphics.hpp>

class Triangle{
    Point a,b,c;
    Point cmc;
    float radius;
public:
    Triangle(sf::Vertex a,sf::Vertex b,sf::Vertex c);
    void calc_center();
    Point geta();
    Point getb();
    Point getc();
};

#endif //OOP_TRIANGLE_H
