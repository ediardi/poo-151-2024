//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_DRAWABLES_H
#define OOP_DRAWABLES_H

#include <SFML/Graphics.hpp>
#include "ColoredTriangle.h"
#include "Triangle.h"

class ColoredTriangle;
class Triangle;

class Drawables : public sf::Drawable{
private:
    static sf::VertexArray points;
    static std::vector<ColoredTriangle> triangles;
    static std::vector<sf::CircleShape> circles;
    static inline int trianglepoints=0;
public:
    static void add(sf::Vertex x);
    static sf::CircleShape* add_circle(Point origin,float rad);
    static void change_circle_color(sf::CircleShape& reference,sf::Color color);
    static void clear_all();
    static ColoredTriangle * add_triangle(const Triangle* triangle);
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //OOP_DRAWABLES_H
