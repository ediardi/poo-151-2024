//
// Created by eciuc on 6/3/2024.
//

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