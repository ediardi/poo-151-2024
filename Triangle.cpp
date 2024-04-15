//
// Created by eciuc on 4/3/2024.
//

#include "Triangle.h"
#include "Drawables.h"
#include <SFML/Graphics.hpp>
#include <cmath>


Triangle::Triangle(sf::Vertex a,sf::Vertex b,sf::Vertex c): a(a),b(b),c(c){
    circumcircle_center=Point();
    calc_center();
}
Triangle::Triangle(Point a, Point b, Point c): a(a),b(b),c(c) {
    circumcircle_center=Point();
    calc_center();
}
void Triangle::calc_center(){ // de facut :transform in constructor, fac destructor , copiere operator <<
    circumcircle_center.x= ((a.x * a.x + a.y * a.y) * (b.y - c.y) + (b.x * b.x + b.y * b.y) *
                                                                    (c.y - a.y) + (c.x * c.x + c.y * c.y) * (a.y - b.y))
                           / ((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) * 2);
    circumcircle_center.y= ((a.x * a.x + a.y * a.y) * (c.x - b.x) + (b.x * b.x + b.y * b.y) *
                                                                    (a.x - c.x) + (c.x * c.x + c.y * c.y) * (b.x - a.x))
                           / ((a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y)) * 2);
    radius = sqrtf((a.x - circumcircle_center.x) * (a.x - circumcircle_center.x) + (a.y - circumcircle_center.y) * (a.y - circumcircle_center.y));
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

void Triangle::add_on_screen() {
    Drawables::add_triangle(Triangle(*this));
}

void Triangle::add_circumcircle_on_screen() {
    Drawables::add_circle(circumcircle_center, radius);
    Drawables::add(circumcircle_center.tovertex());
}

void Triangle::seta(Point pointa) {
    this->a=pointa;
}

void Triangle::setb(Point pointb) {
    this->b=pointb;
}

void Triangle::setc(Point pointc) {
    this->c=pointc;
}

Triangle::Triangle(const Triangle &other): a(other.a), b(other.b), c(other.c) {

}

Triangle::Triangle() = default;
