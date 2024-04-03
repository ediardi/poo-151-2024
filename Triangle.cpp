//
// Created by eciuc on 4/3/2024.
//

#include "Triangle.h"
#include "Drawables.h"
#include <SFML/Graphics.hpp>
#include <cmath>


Triangle::Triangle(sf::Vertex a,sf::Vertex b,sf::Vertex c): a(a),b(b),c(c){
    cmc=Point();
    calc_center();
}
void Triangle::calc_center(){ // transform in constructor, fac destructor , copiere operator <<
    cmc.x= ((a.x * a.x + a.y * a.y) * (b.y - c.y) + (b.x * b.x + b.y * b.y) * (c.y - a.y) + (c.x * c.x + c.y * c.y) * (a.y - b.y))
           / ((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) * 2);
    cmc.y= ((a.x * a.x + a.y * a.y) * (c.x - b.x) + (b.x * b.x + b.y * b.y) * (a.x - c.x) + (c.x * c.x + c.y * c.y) * (b.x - a.x))
           / ((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) * 2);
    radius = sqrtf((a.x - cmc.x) * (a.x - cmc.x) + (a.y - cmc.y) * (a.y - cmc.y));
    Drawables::add_circle(cmc,radius);
    Drawables::add(cmc.tovertex());
}

Point Triangle::geta() {
    return a;
}

Point Triangle::getb() {
    return b;
}

Point Triangle::getc() {
    return c;
}
