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

float inline modul(Point a)
{
    return (a.getx() * a.getx() + a.gety() * a.gety());
}

void Triangle::calc_center(){ // de facut :transform in constructor, fac destructor , copiere operator <<
    float d= ((a.getx() * (b.gety() - c.gety()) + b.getx() * (c.gety() - a.gety()) + c.getx() * (a.gety() - b.gety())) * 2);
    float x=(modul(a) * (b.gety() - c.gety()) + modul(b) * (c.gety() - a.gety()) + modul(c) * (a.gety() - b.gety()))/ d;
    float y=(modul(a) * (c.getx() - b.getx()) + modul(b) * (a.getx() - c.getx()) + modul(c) * (b.getx() - a.getx()))/ d;
    circumcircle_center.setx(x);
    circumcircle_center.sety(y);
    radius = sqrtf((a.getx() - x) * (a.getx() - x) + (a.gety() - y) * (a.gety() - y));
}

Point Triangle::geta() const {
    return a;
}

Point Triangle::getb() const {
    return b;
}

Point Triangle::getc() const {
    return c;
}

ColoredTriangle* Triangle::add_on_screen() {
    return Drawables::add_triangle(this);
}

sf::CircleShape* Triangle::add_circumcircle_on_screen() {
    Drawables::add(circumcircle_center.tovertex());
    return Drawables::add_circle(circumcircle_center, radius);
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

bool Triangle::is_inside_circle(Point origin, float radius) const{
    if(Line(origin,a).length()>radius)
        return false;
    if(Line(origin,b).length()>radius)
        return false;
    if(Line(origin,c).length()>radius)
        return false;
    return true;
}

bool Triangle::does_not_intersect_triangle(Triangle other) const{
    Line other_ab= Line(other.a,other.b);
    Line other_bc= Line(other.b,other.c);
    Line other_ca= Line(other.c,other.a);
    Line ab= Line(a,b);
    Line bc= Line(b,c);
    Line ca= Line(c,a);
    if(ab.intersects(other_ab)||ab.intersects(other_bc)||ab.intersects(other_ca))
        return false;
    if(bc.intersects(other_ab)||bc.intersects(other_bc)||bc.intersects(other_ca))
        return false;
    if(ca.intersects(other_ab)||ca.intersects(other_bc)||ca.intersects(other_ca))
        return false;
    return true;
}

Point Triangle::getcenter() const{
    return circumcircle_center;
}

float Triangle::getradius() const{
    return radius;
}

Triangle::Triangle() = default;
