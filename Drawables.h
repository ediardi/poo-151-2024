//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_DRAWABLES_H
#define OOP_DRAWABLES_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Triangle.h"
#include "ColoredTriangle.h"

class Triangle;
class ColoredTriangle;

class Drawables : public sf::Drawable{
private:
    static sf::VertexArray points;
    static std::unordered_map<int, ColoredTriangle> triangles;
    static std::unordered_map<int, sf::CircleShape> circles;
public:
    static void add(sf::Vertex x);
    static int add_circle(Point origin,float rad);
    //static void change_circle_color(sf::CircleShape& reference,sf::Color color);
    static void clear_all();
    static int add_triangle(const Triangle& triangle);
    static void change_circle_color(int index, sf::Color new_color);
    static void change_triangle_color(int index, sf::Color new_color);
    [[nodiscard]] static sf::Color get_circle_color(int index) ;
    [[nodiscard]] static sf::Color get_triangle_color(int index) ;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //OOP_DRAWABLES_H
