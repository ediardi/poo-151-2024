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
    trianglepoints=0;
}

void Drawables::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(points);
    for(auto& circle:circles)
    {
        target.draw(circle);
    }
    sf::VertexArray linepoints(sf::Lines,0);
    for(const auto& triangle_struct:triangles)
    {
        sf::Vertex p;
        Point a=triangle_struct.triangle->geta();
        Point b=triangle_struct.triangle->getb();
        Point c=triangle_struct.triangle->getc();

        p=a.tovertex();
        p.color=triangle_struct.color;
        linepoints.append(p);
        p=b.tovertex();
        p.color=triangle_struct.color;
        linepoints.append(p);

        p=b.tovertex();
        p.color=triangle_struct.color;
        linepoints.append(p);
        p=c.tovertex();
        p.color=triangle_struct.color;
        linepoints.append(p);

        p=c.tovertex();
        p.color=triangle_struct.color;
        linepoints.append(p);
        p=a.tovertex();
        p.color=triangle_struct.color;
        linepoints.append(p);
    }
    target.draw(linepoints);
}

ColoredTriangle * Drawables::add_triangle(const Triangle* triangle) {
    triangles.push_back(ColoredTriangle(triangle,sf::Color::White));
    return &triangles.back();
}

