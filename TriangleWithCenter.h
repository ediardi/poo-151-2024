//
// Created by eciuc on 6/3/2024.
//

#ifndef OOP_TRIANGLEWITHCENTER_H
#define OOP_TRIANGLEWITHCENTER_H


#include "Triangle.h"

class TriangleWithCenter : public Triangle{

    Point circumscribed_circle_center;
    float radius=0;
    void calc_center();
    [[nodiscard]] bool same_side_as_center(const Point& d,const Point& e,const Point& f) const;
public:
    TriangleWithCenter& operator=(const TriangleWithCenter& other);
    [[nodiscard]] int add_circumscribed_circle_on_screen() const;
    [[nodiscard]] Point get_center() const;
    [[nodiscard]] float get_radius() const;
    [[nodiscard]] float best_area() const override;
    TriangleWithCenter(Point a, Point b, Point c);
    TriangleWithCenter(const TriangleWithCenter &other);

    TriangleWithCenter();
};


#endif //OOP_TRIANGLEWITHCENTER_H
