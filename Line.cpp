//
// Created by eciuc on 4/9/2024.
//

#include "Line.h"
#include "cmath"

Point Line::startpoint() { return a;}

Point Line::endpoint() { return b;}

Line::Line(Point a1, Point b1) : a(a1),b(b1) {}

float Line::get_length() const{
    float length_x= b.getx() - a.getx();
    float length_y= b.gety() - a.gety();
    return sqrtf(length_x * length_x + length_y * length_y);
}

std::ostream &operator<<(std::ostream &os, const Line &line) {
    os << "Line has length " << line.get_length() << std::endl;
    return os;
}
