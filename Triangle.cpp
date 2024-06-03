//
// Created by eciuc on 4/3/2024.
//

#include "Triangle.h"
#include "Drawables.h"
#include <SFML/Graphics.hpp>
#include <cmath>


/*Triangle::Triangle(sf::Vertex a,sf::Vertex b,sf::Vertex c): a(a),b(b),c(c){
    circumscribed_circle_center=Point();
    calc_center();
}
*/
Triangle::Triangle(Point a, Point b, Point c): a(a),b(b),c(c) {
}

float Triangle::get_area() const
{
    return fabsf(get_signed_area());
}

float Triangle::get_signed_area() const
{
    return (a.getx()*b.gety() - a.getx()*c.gety() + b.getx()*c.gety() - b.getx()*a.gety() + c.getx()*a.gety() - c.getx()*b.gety())/2;
}

float Triangle::get_signed_area(const Point& d,const Point& e,const Point& f)
{
    return (d.getx() * e.gety() - d.getx() * f.gety() + e.getx() * f.gety() - e.getx() * d.gety() + f.getx() * d.gety() - f.getx() * e.gety()) / 2;
}

Point Triangle::get_a() const {
    return a;
}

Point Triangle::get_b() const {
    return b;
}

Point Triangle::get_c() const {
    return c;
}

int Triangle::add_on_screen() const {
    return Drawables::add_triangle(*this);
}

void Triangle::set_a(const Point& point_a) {
    this->a=point_a;
}

void Triangle::set_b(const Point& point_b) {
    this->b=point_b;
}

void Triangle::set_c(const Point& point_c) {
    this->c=point_c;
}

Triangle::Triangle() = default ;
Triangle::Triangle(const Triangle &other): a(other.a), b(other.b), c(other.c) {
    //just to bypass =default suggestion/warning
    a=other.a;
}

bool Triangle::does_not_intersect_triangle(const Triangle& other) const{
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

std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
    os << "Triangle is formed with the following points:" << std::endl;
    os << triangle.a << triangle.b << triangle.c;
    os << "Triangle has edges of the following lengths:" << std::endl;
    os << Line(triangle.a,triangle.b) << Line(triangle.b,triangle.c) << Line(triangle.c,triangle.a) << std::endl;
    return os;
}

Triangle &Triangle::operator=(const Triangle &other) {
    a=other.a;
    b=other.b;
    c=other.c;
    //to avoid warning
    c=other.c;
    return *this;
}

Triangle::~Triangle() = default;



