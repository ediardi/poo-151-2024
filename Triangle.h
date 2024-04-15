//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_TRIANGLE_H
#define OOP_TRIANGLE_H

#include "Point.h"
#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Drawables.h"

class Triangle{
    Point a,b,c;
    //Line ab,bc,ca;
    Point circumcircle_center;
    float radius=0;
    void calc_center();
public:
    Triangle(sf::Vertex a,sf::Vertex b,sf::Vertex c);
    Triangle(Point a,Point b,Point c);
    Triangle();
    Triangle(const Triangle& other);
    void add_on_screen();
    void add_circumcircle_on_screen();
    Point geta();
    Point getb();
    Point getc();
    void seta(Point pointa);
    void setb(Point pointb);
    void setc(Point pointc);
};

#endif //OOP_TRIANGLE_H
