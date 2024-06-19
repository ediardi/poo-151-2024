//
// Created by eciuc on 4/3/2024.
//

#ifndef OOP_DRAWABLES_H
#define OOP_DRAWABLES_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Point.h"
#include "Line.h"

class Node;


class Drawables : public sf::Drawable{
private:
    static sf::VertexArray points;
    static sf::VertexArray lines;
    static std::unordered_map<int, sf::CircleShape> circles;
    static std::unordered_map<int, sf::CircleShape> pawns;
public:
    static void add(sf::Vertex x,sf::Color col,float radius = 5);
    static void move_pawn(int index, const Node& x);
    static int add_node(Point origin, float radius);
    static void add_line(Line l);
    //static void change_circle_color(sf::CircleShape& reference,sf::Color color);
    static void clear_all();
    static void change_circle_color(int index, sf::Color new_color);
    //[[nodiscard]] static sf::Color get_circle_color(int index) ;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //OOP_DRAWABLES_H
