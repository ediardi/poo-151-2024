//
// Created by eciuc on 4/3/2024.
//

#include <SFML/Graphics.hpp>
#include "Point.h"


Point::Point(sf::Vertex v){
     this->x=v.position.x;
     this->y=v.position.y;
}
Point::Point()= default;
Point::Point(int x,int y)
    {
        this->x= static_cast<float>(x);
        this->y= static_cast<float>(y);
    }
void Point::setx(float new_x){this->x=new_x;}
void Point::sety(float new_y){this->y=new_y;}
float Point::getx() const{return x;}
float Point::gety() const{return y;}
sf::Vertex Point::to_vertex() const
{
    sf::Vector2f temp1(x,y);
    sf::Vertex temp(temp1,sf::Color::White);
    return temp;
}

Point::Point(float x, float y) {
    {
        this->x= x;
        this->y= y;
    }
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << point.x << " " << point.y << std::endl;
    return os;
}

bool operator==(const Point &a, const Point &b) {
    if(a.x==b.x && a.y == b.y)
        return true;
    return false;
}

