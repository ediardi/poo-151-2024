//
// Created by eciuc on 4/3/2024.
//

#include "Drawables.h"


void Drawables::add(sf::Vertex x) {
    points.append(x);
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
    target.draw(points);

    target.draw(lines);

    for(const auto &item:circles)
    {
        auto circle =item.second;
        target.draw(circle);
    }
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


/*sf::Color Drawables::get_circle_color(const int index) {
    return circles[index].getOutlineColor();
}*/

