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
void Point::inc_color(){
    color_index++;
}
void Point::setx(float new_x){this->x=new_x;}
void Point::sety(float new_y){this->y=new_y;}
float Point::getx() const{return x;}
float Point::gety() const{return y;}
sf::Vertex Point::tovertex()
{
    sf::Vector2f temp1(x,y);
    sf::Vertex temp(temp1,color[color_index]);
    return temp;
}
