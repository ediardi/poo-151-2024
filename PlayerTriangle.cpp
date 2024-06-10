//
// Created by eciuc on 6/3/2024.
//

#include <cmath>
#include "PlayerTriangle.h"

bool PlayerTriangle::is_inside_circle(const Point origin,const float other_radius) const{
    if(Line(origin, a).get_length() > other_radius)
        return false;
    if(Line(origin, b).get_length() > other_radius)
        return false;
    if(Line(origin, c).get_length() > other_radius)
        return false;
    return true;
}

PlayerTriangle::PlayerTriangle() = default;

float PlayerTriangle::get_area() const
{
    if(a==b)
        throw DegenerateTriangle("matching points a and b");
    if(b==c)
        throw DegenerateTriangle("matching points b and c");
    if(a==c)
        throw DegenerateTriangle("matching points a and c");
    return fabsf(get_signed_area());
}