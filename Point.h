//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_POINT_H
#define OOP_POINT_H

#include <SFML/Graphics.hpp>

class Point {
    float x;
    float y;
    int color_index=0;
public:
    Point(sf::Vertex v);
    Point();
    Point(int x,int y);
    Point(float x,float y);
    void setx(float new_x);
    void sety(float new_y);
    float getx() const;
    float gety() const;
    sf::Vertex tovertex();
};

#endif //OOP_POINT_H
