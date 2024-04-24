//
// Created by eciuc on 4/16/2024.
//

#include "ColoredTriangle.h"

ColoredTriangle::ColoredTriangle(const Triangle& triangle1, sf::Color color1): triangle(triangle1),color(color1) {

}

void ColoredTriangle::set_color(sf::Color new_color) {
    color=new_color;
}

Triangle ColoredTriangle::get_triangle() const{
    return triangle;
}

sf::Color ColoredTriangle::get_color() const {
    return color;
}

