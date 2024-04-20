//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_TRIANGLE_H
#define OOP_TRIANGLE_H

#include "ColoredTriangle.h"
#include "Point.h"
#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Drawables.h"

class ColoredTriangle;

class Triangle{
    Point a,b,c;
    //Line ab,bc,ca;
    Point circumscribed_circle_center;
    float radius=0;
    void calc_center();

    [[nodiscard]] float get_signed_area() const;

    [[nodiscard]] static float get_signed_area(const Point& d,const Point& e,const Point& f) ;

    [[nodiscard]] bool same_side_as_center(const Point& d,const Point& e,const Point& f) const;
public:
    //Triangle(sf::Vertex a,sf::Vertex b,sf::Vertex c);
    Triangle(Point a,Point b,Point c);
    Triangle();
    Triangle(const Triangle& other);
    ~Triangle();
    [[nodiscard]] ColoredTriangle* add_on_screen() const;
    [[nodiscard]] sf::CircleShape* add_circumscribed_circle_on_screen() const;
    [[nodiscard]] Point get_a() const;
    [[nodiscard]] Point get_b() const;
    [[nodiscard]] Point get_c() const;
    [[nodiscard]] Point get_center() const;
    [[nodiscard]] float get_radius() const;
    void set_a(const Point& point_a);
    void set_b(const Point& point_b);
    void set_c(const Point& point_c);
    [[nodiscard]] bool is_inside_circle(Point origin,float other_radius) const;
    [[nodiscard]] bool does_not_intersect_triangle(const Triangle& other) const;
    [[nodiscard]] float get_area() const;
    [[nodiscard]] float best_area() const;
    friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle);
};

#endif //OOP_TRIANGLE_H
