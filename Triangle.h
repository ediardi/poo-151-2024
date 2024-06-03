//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_TRIANGLE_H
#define OOP_TRIANGLE_H

#include "Point.h"
#include <SFML/Graphics.hpp>
#include "Line.h"

class Triangle{
    //Line ab,bc,ca;

    [[nodiscard]] float get_signed_area() const;

protected:
    Point a;
    Point b;
    Point c;
    [[nodiscard]] static float get_signed_area(const Point& d,const Point& e,const Point& f) ;

public:
    //Triangle(sf::Vertex a,sf::Vertex b,sf::Vertex c);
    Triangle(Point a,Point b,Point c);
    Triangle();
    Triangle(const Triangle& other);
    Triangle& operator=(const Triangle& other);
    ~Triangle();
    [[nodiscard]] int add_on_screen() const;
    [[nodiscard]] Point get_a() const;
    [[nodiscard]] Point get_b() const;
    [[nodiscard]] Point get_c() const;
    void set_a(const Point& point_a);
    void set_b(const Point& point_b);
    void set_c(const Point& point_c);
    [[nodiscard]] bool does_not_intersect_triangle(const Triangle& other) const;
    [[nodiscard]] float get_area() const;
    friend std::ostream& operator<<(std::ostream& os, const Triangle& triangle);

    [[nodiscard]] virtual float best_area() const {
        return  get_area();
    };
};

#endif //OOP_TRIANGLE_H
