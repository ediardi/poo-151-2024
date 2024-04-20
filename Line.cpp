//
// Created by eciuc on 4/9/2024.
//

#include "Line.h"
#include "cmath"

//Point Line::startpoint() { return a;}

//Point Line::endpoint() { return b;}

Line::Line(Point a1, Point b1) : a(a1),b(b1) {}

bool Line::intersects(Line line) const{
    // credit goes to https://stackoverflow.com/questions/563198/how-do-you-detect-where-two-line-segments-intersect
    // Returns 1 if the lines intersect, otherwise 0. In addition, if the lines
    // p0= a
    // p1 =b
    // p2 =line.a
    // p3 =line.b
    {
        float s1_x, s1_y, s2_x, s2_y;
        s1_x = b.getx() - a.getx();                 s1_y = b.gety() - a.gety();
        s2_x = line.b.getx() - line.a.getx();        s2_y = line.b.gety() - line.a.gety();

        float s, t;
        s = (-s1_y * (a.getx() - line.a.getx()) + s1_x * (a.gety() - line.a.gety())) / (-s2_x * s1_y + s1_x * s2_y);
        t = ( s2_x * (a.gety() - line.a.gety()) - s2_y * (a.getx() - line.a.getx())) / (-s2_x * s1_y + s1_x * s2_y);

        if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
        {
            // Collision detected
            return true;
        }

        return false; // No collision
    }
}

float Line::get_length() const{
    float length_x= b.getx() - a.getx();
    float length_y= b.gety() - a.gety();
    return sqrtf(length_x * length_x + length_y * length_y);
}

std::ostream &operator<<(std::ostream &os, const Line &line) {
    os << "Line has length " << line.get_length() << std::endl;
    return os;
}
