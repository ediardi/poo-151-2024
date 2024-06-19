//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_POINT_H
#define OOP_POINT_H

#include <SFML/Graphics.hpp>

class Point {
    float x{};
    float y{};
public:
    explicit Point(sf::Vertex v);
    Point();
    Point(int x,int y);
    Point(float x,float y);
    //void setx(float new_x);
    //void sety(float new_y);
    [[nodiscard]] float getx() const;
    [[nodiscard]] float gety() const;
    [[nodiscard]] sf::Vertex to_vertex() const;
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
    friend bool operator==(const Point& a,const Point& b) ;
};

#endif //OOP_POINT_H
