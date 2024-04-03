//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_POINT_H
#define OOP_POINT_H

#include <SFML/Graphics.hpp>

class Point {
    float x;
    float y;
    sf::Color color[7]={sf::Color::White,sf::Color::Yellow,sf::Color::Red
            ,sf::Color::Green, sf::Color::Magenta, sf::Color::Cyan
            , sf::Color::Blue};
    int color_index=0;
public:
    Point(sf::Vertex v);
    Point();
    Point(int x,int y);
    void inc_color();
    void setx(float new_x);
    void sety(float new_y);
    float getx() const;
    float gety() const;
    sf::Vertex tovertex();
    friend class Triangle;
};

#endif //OOP_POINT_H
