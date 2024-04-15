//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_DRAWABLES_H
#define OOP_DRAWABLES_H

#include <SFML/Graphics.hpp>
#include "Triangle.h"

class Triangle;

class Drawables : public sf::Drawable{

    static sf::VertexArray points;
    static std::vector<Triangle> triangles;
    static std::vector<sf::CircleShape> circles;
    static inline int trianglepoints=0;
public:
    static void add(sf::Vertex x);
    static void add_triangle_vertex(sf::Vertex x);
    static void add_circle(Point origin,float rad);
    static void clear_all();
    static void add_triangle(Triangle triangle);
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //OOP_DRAWABLES_H
