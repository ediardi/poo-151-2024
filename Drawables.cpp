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

void Drawables::add_circle(Point origin, float rad) {
    sf::CircleShape cir(rad,60);
    cir.setOrigin(rad,rad);
    cir.setPosition(origin.getx(),origin.gety());
    cir.setOutlineColor(sf::Color::White);
    cir.setFillColor(sf::Color::Transparent);
    cir.setOutlineThickness(1);
    circles.push_back(cir);
}

void Drawables::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(points);
    for(auto& cir:circles)
    {
        target.draw(cir);
    }
    sf::VertexArray linepoints(sf::Lines,0);
    for(auto tr:triangles)
    {
        linepoints.append(tr.geta().tovertex());
        linepoints.append(tr.getb().tovertex());

        linepoints.append(tr.getb().tovertex());
        linepoints.append(tr.getc().tovertex());

        linepoints.append(tr.getc().tovertex());
        linepoints.append(tr.geta().tovertex());
    }
    target.draw(linepoints);
}

