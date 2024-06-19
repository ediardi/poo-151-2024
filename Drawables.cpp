//
// Created by eciuc on 4/3/2024.
//

#include "Drawables.h"
#include "Node.h"


void Drawables::add(sf::Vertex x,sf::Color col,float radius) {
    sf::CircleShape circle(radius,30);
    circle.setOrigin(radius,radius);
    circle.setPosition(x.position.x,x.position.y);
    circle.setOutlineColor(col);
    circle.setFillColor(col);
    circle.setOutlineThickness(1);
    int new_index=(int)pawns.size();
    pawns[new_index]=circle;
}

int Drawables::add_node(Point origin, float radius=10) {
    sf::CircleShape circle(radius,60);
    circle.setOrigin(radius,radius);
    circle.setPosition(origin.getx(),origin.gety());
    circle.setOutlineColor(sf::Color::White);
    circle.setFillColor(sf::Color::Black);
    circle.setOutlineThickness(1);
    int new_index=(int)circles.size();
    circles[new_index]=circle;
    return new_index;
}

void Drawables::clear_all() {
    points.clear();
    circles.clear();
}

void Drawables::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // to do: delete (placed here to avoid unused warning)
    states.texture=states.texture;
    //

    target.draw(lines);

    for(const auto &item:circles)
    {
        auto circle =item.second;
        target.draw(circle);
    }

    for(const auto &item:pawns)
    {
        auto circle =item.second;
        target.draw(circle);
    }

    target.draw(points);
}

void Drawables::change_circle_color(const int index, const sf::Color new_color) {
    circles[index].setOutlineColor(new_color);
}

void Drawables::add_line(Line l) {
    auto x=l.startpoint().to_vertex();
    lines.append(x);
    auto y=l.endpoint().to_vertex();
    lines.append(y);
}

void Drawables::move_pawn(int index, const Node& x) {
    pawns[index].setPosition( x.to_vertex().position );
}


/*sf::Color Drawables::get_circle_color(const int index) {
    return circles[index].getOutlineColor();
}*/

