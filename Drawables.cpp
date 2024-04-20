//
// Created by eciuc on 4/3/2024.
//

#include "Drawables.h"


void Drawables::add(sf::Vertex x) {
    points.append(x);
}

int Drawables::add_circle(Point origin, float radius) {
    sf::CircleShape circle(radius,60);
    circle.setOrigin(radius,radius);
    circle.setPosition(origin.getx(),origin.gety());
    circle.setOutlineColor(sf::Color::White);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(1);
    int new_index=(int)circles.size();
    circles[new_index]=circle;
    return new_index;
}

void Drawables::clear_all() {
    points.clear();
    triangles.clear();
    circles.clear();
}

void Drawables::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // to do: delete (placed here to avoid unused warning)
    states.texture=states.texture;
    //
    target.draw(points);
    for(const auto &[index,circle]:circles)
    {
        target.draw(circle);
    }
    sf::VertexArray line_points(sf::Lines, 0);
    for(const auto& [index,triangle_struct]:triangles)
    {
        sf::Vertex p;
        Point a= triangle_struct.triangle->get_a();
        Point b= triangle_struct.triangle->get_b();
        Point c= triangle_struct.triangle->get_c();

        p= a.to_vertex();
        p.color=triangle_struct.color;
        line_points.append(p);
        p= b.to_vertex();
        p.color=triangle_struct.color;
        line_points.append(p);

        p= b.to_vertex();
        p.color=triangle_struct.color;
        line_points.append(p);
        p= c.to_vertex();
        p.color=triangle_struct.color;
        line_points.append(p);

        p= c.to_vertex();
        p.color=triangle_struct.color;
        line_points.append(p);
        p= a.to_vertex();
        p.color=triangle_struct.color;
        line_points.append(p);
    }
    target.draw(line_points);
}

int Drawables::add_triangle(const Triangle* triangle) {
    int new_index=(int)triangles.size();
    auto colored_triangle= ColoredTriangle(triangle,sf::Color::White);
    triangles[new_index]= colored_triangle;
    return new_index;
}

void Drawables::change_circle_color(const int index, const sf::Color new_color) {
    circles[index].setOutlineColor(new_color);
}

void Drawables::change_triangle_color(const int index, const sf::Color new_color) {
    triangles[index].color=new_color;
}

sf::Color Drawables::get_circle_color(const int index) {
    return circles[index].getOutlineColor();
}

sf::Color Drawables::get_triangle_color(const int index) {
    return triangles[index].color;
}

