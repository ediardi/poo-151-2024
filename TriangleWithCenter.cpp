//
// Created by eciuc on 6/3/2024.
//

#include "TriangleWithCenter.h"
#include "Drawables.h"
#include <cmath>

float inline module(Point a)
{
    return (a.getx() * a.getx() + a.gety() * a.gety());
}

void TriangleWithCenter::calc_center(){
    float d= ((a.getx() * (b.gety() - c.gety()) + b.getx() * (c.gety() - a.gety()) + c.getx() * (a.gety() - b.gety())) * 2);
    float x= (module(a) * (b.gety() - c.gety()) + module(b) * (c.gety() - a.gety()) + module(c) * (a.gety() - b.gety())) / d;
    float y= (module(a) * (c.getx() - b.getx()) + module(b) * (a.getx() - c.getx()) + module(c) * (b.getx() - a.getx())) / d;
    circumscribed_circle_center.setx(x);
    circumscribed_circle_center.sety(y);
    radius = sqrtf((a.getx() - x) * (a.getx() - x) + (a.gety() - y) * (a.gety() - y));
}

bool TriangleWithCenter::same_side_as_center(const Point& d,const Point& e,const Point& f) const
{
    float sign1=get_signed_area(d,e,f);
    float sign2=get_signed_area(d, e, circumscribed_circle_center);
    if((fabsf(sign1) == 0.0f || fabsf(sign2) == 0.0f))
    {
        return true;
    }
    return (sign1>=0)==(sign2>=0);
}

 float  TriangleWithCenter::best_area() const
{
    float best_area=get_area();
    float distance_from_center;
    float potential_height;
    float line_length;
    float potential_area;

    line_length= Line(a, b).get_length();
    distance_from_center = 2 * fabsf(get_signed_area(a, b, circumscribed_circle_center)) / line_length;
    if(same_side_as_center(a,b,c))
    {
        potential_height=radius-distance_from_center;
    }
    else
    {
        potential_height=radius+distance_from_center;
    }
    if(potential_height > line_length)
        potential_area= sqrtf(3)*3/4*radius*radius;
    else
        potential_area= potential_height * line_length / 2;

    best_area= fmaxf(best_area,potential_area);

    line_length= Line(b, c).get_length();
    distance_from_center = 2 * fabsf(get_signed_area(b, c, circumscribed_circle_center)) / line_length;
    if(same_side_as_center(b,c,a))
    {
        potential_height=radius-distance_from_center;
    }
    else
    {
        potential_height=radius+distance_from_center;
    }
    if(potential_height > line_length)
        potential_area= sqrtf(3)*3/4*radius*radius;
    else
        potential_area= potential_height * line_length / 2;

    best_area= fmaxf(best_area,potential_area);

    line_length= Line(c, a).get_length();
    distance_from_center = 2 * fabsf(get_signed_area(c, a, circumscribed_circle_center)) / line_length;
    if(same_side_as_center(c,a,b))
    {
        potential_height=radius-distance_from_center;
    }
    else
    {
        potential_height=radius+distance_from_center;
    }
    if(potential_height > line_length)
        potential_area= sqrtf(3)*3/4*radius*radius;
    else
        potential_area= potential_height * line_length / 2;

    best_area= fmaxf(best_area,potential_area);

    return best_area;
}

int TriangleWithCenter::add_circumscribed_circle_on_screen() const {
    Drawables::add(circumscribed_circle_center.to_vertex());
    return Drawables::add_circle(circumscribed_circle_center, radius);
}

Point TriangleWithCenter::get_center() const{
    return circumscribed_circle_center;
}

float TriangleWithCenter::get_radius() const{
    return radius;
}

TriangleWithCenter &TriangleWithCenter::operator=(const TriangleWithCenter &other) {
    static_cast<Triangle&>(*this) = other;
    //https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es63-dont-slice
    radius=other.radius;
    circumscribed_circle_center=other.circumscribed_circle_center;
    calc_center();
    return *this;
}

TriangleWithCenter::TriangleWithCenter(Point a, Point b, Point c) : Triangle(a,b,c), circumscribed_circle_center(Point()) {
    calc_center();
}

TriangleWithCenter::TriangleWithCenter(const TriangleWithCenter &other): Triangle(other), circumscribed_circle_center(other.circumscribed_circle_center), radius(other.radius) {
    //just to bypass =default suggestion/warning
    radius=other.radius;
}

TriangleWithCenter::TriangleWithCenter() = default;
