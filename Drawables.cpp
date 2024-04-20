//
// Created by eciuc on 4/3/2024.
//

#include "Drawables.h"


void Drawables::add(sf::Vertex x) {
    points.append(x);
}

sf::CircleShape* Drawables::add_circle(Point origin, float radius) {
    sf::CircleShape circle(radius,60);
    circle.setOrigin(radius,radius);
    circle.setPosition(origin.getx(),origin.gety());
    circle.setOutlineColor(sf::Color::White);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(1);
    circles.push_back(circle);
    return &circles.back();
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
    for(auto& circle:circles)
    {
        target.draw(circle);
    }
    sf::VertexArray line_points(sf::Lines, 0);
    for(const auto& triangle_struct:triangles)
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

ColoredTriangle * Drawables::add_triangle(const Triangle* triangle) {
    triangles.push_back(ColoredTriangle(triangle,sf::Color::White));
    return &triangles.back();
}

