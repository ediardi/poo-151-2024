//
// Created by eciuc on 4/3/2024.
//

#include "Drawables.h"


void Drawables::add(sf::Vertex x) {
    points.append(x);
}

void Drawables::add_triangle_vertex(sf::Vertex x) {
    points.append(x);
    trianglepoints++;
    if(trianglepoints%3==0)
    {
        int n=points.getVertexCount();
        triangles.emplace_back(points[n-1],points[n-2],points[n-3]);
    }
}

void Drawables::add_circle(Point origin, float radius) {
    sf::CircleShape circle(radius,60);
    circle.setOrigin(radius,radius);
    circle.setPosition(origin.getx(),origin.gety());
    circle.setOutlineColor(sf::Color::White);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(1);
    circles.push_back(circle);
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
    for(auto triangle:triangles)
    {
        linepoints.append(triangle.geta().tovertex());
        linepoints.append(triangle.getb().tovertex());

        linepoints.append(triangle.getb().tovertex());
        linepoints.append(triangle.getc().tovertex());

        linepoints.append(triangle.getc().tovertex());
        linepoints.append(triangle.geta().tovertex());
    }
    target.draw(linepoints);
}

void Drawables::add_triangle(Triangle triangle) {
    triangles.push_back(triangle);
}

