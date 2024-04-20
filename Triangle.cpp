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
    circumscribed_circle_center=Point();
    calc_center();
}

float inline module(Point a)
{
    return (a.getx() * a.getx() + a.gety() * a.gety());
}

void Triangle::calc_center(){ // de facut :transform in constructor, fac destructor , copiere operator <<
    float d= ((a.getx() * (b.gety() - c.gety()) + b.getx() * (c.gety() - a.gety()) + c.getx() * (a.gety() - b.gety())) * 2);
    float x= (module(a) * (b.gety() - c.gety()) + module(b) * (c.gety() - a.gety()) + module(c) * (a.gety() - b.gety())) / d;
    float y= (module(a) * (c.getx() - b.getx()) + module(b) * (a.getx() - c.getx()) + module(c) * (b.getx() - a.getx())) / d;
    circumscribed_circle_center.setx(x);
    circumscribed_circle_center.sety(y);
    radius = sqrtf((a.getx() - x) * (a.getx() - x) + (a.gety() - y) * (a.gety() - y));
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

bool Triangle::same_side_as_center(const Point& d,const Point& e,const Point& f) const
{
    float sign1=get_signed_area(d,e,f);
    float sign2=get_signed_area(d, e, circumscribed_circle_center);
    if((fabsf(sign1) == 0.0f || fabsf(sign2) == 0.0f))
    {
        return true;
    }
    return (sign1>=0)==(sign2>=0);
}

float  Triangle::best_area() const
{
    float best_area=get_area();
    float distance_from_center;
    float potential_height;
    float line_lenght;
    float potential_area;

    line_lenght= Line(a, b).get_length();
    distance_from_center = 2 * fabsf(get_signed_area(a, b, circumscribed_circle_center)) / line_lenght;
    if(same_side_as_center(a,b,c))
    {
        potential_height=radius-distance_from_center;
    }
    else
    {
        potential_height=radius+distance_from_center;
    }
    if(potential_height>line_lenght)
        potential_area= sqrtf(3)*3/4*radius*radius;
    else
        potential_area=potential_height*line_lenght/2;

    best_area= fmaxf(best_area,potential_area);

    line_lenght= Line(b, c).get_length();
    distance_from_center = 2 * fabsf(get_signed_area(b, c, circumscribed_circle_center)) / line_lenght;
    if(same_side_as_center(b,c,a))
    {
        potential_height=radius-distance_from_center;
    }
    else
    {
        potential_height=radius+distance_from_center;
    }
    if(potential_height>line_lenght)
        potential_area= sqrtf(3)*3/4*radius*radius;
    else
        potential_area=potential_height*line_lenght/2;

    best_area= fmaxf(best_area,potential_area);

    line_lenght= Line(c, a).get_length();
    distance_from_center = 2 * fabsf(get_signed_area(c, a, circumscribed_circle_center)) / line_lenght;
    if(same_side_as_center(c,a,b))
    {
        potential_height=radius-distance_from_center;
    }
    else
    {
        potential_height=radius+distance_from_center;
    }
    if(potential_height>line_lenght)
        potential_area= sqrtf(3)*3/4*radius*radius;
    else
        potential_area=potential_height*line_lenght/2;

    best_area= fmaxf(best_area,potential_area);

    return best_area;
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
    return Drawables::add_triangle(this);
}

int Triangle::add_circumscribed_circle_on_screen() const {
    Drawables::add(circumscribed_circle_center.to_vertex());
    return Drawables::add_circle(circumscribed_circle_center, radius);
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

Triangle::Triangle() = default;
Triangle::Triangle(const Triangle &other): a(other.a), b(other.b), c(other.c), circumscribed_circle_center(other.circumscribed_circle_center), radius(other.radius) {
}

bool Triangle::is_inside_circle(const Point origin,const float other_radius) const{
    if(Line(origin, a).get_length() > other_radius)
        return false;
    if(Line(origin, b).get_length() > other_radius)
        return false;
    if(Line(origin, c).get_length() > other_radius)
        return false;
    return true;
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

Point Triangle::get_center() const{
    return circumscribed_circle_center;
}

float Triangle::get_radius() const{
    return radius;
}

std::ostream &operator<<(std::ostream &os, const Triangle &triangle) {
    os << "Triangle is formed with the following points:" << std::endl;
    os << triangle.a << triangle.b << triangle.c;
    os << "Triangle has edges of the following lengths:" << std::endl;
    os << Line(triangle.a,triangle.b) << Line(triangle.b,triangle.c) << Line(triangle.c,triangle.a) << std::endl;
    return os;
}

Triangle::~Triangle() = default;



