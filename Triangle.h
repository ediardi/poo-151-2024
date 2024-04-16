//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_TRIANGLE_H
#define OOP_TRIANGLE_H

#include "ColoredTriangle.h"
#include "Point.h"
#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Drawables.h"

class ColoredTriangle;

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
    ColoredTriangle* add_on_screen();
    sf::CircleShape* add_circumcircle_on_screen();
    Point geta() const;
    Point getb() const;
    Point getc() const;
    Point getcenter() const;
    float getradius() const;
    void seta(Point pointa);
    void setb(Point pointb);
    void setc(Point pointc);
    bool is_inside_circle(Point origin,float radius) const;
    bool does_not_intersect_triangle(Triangle other) const;
};

#endif //OOP_TRIANGLE_H
