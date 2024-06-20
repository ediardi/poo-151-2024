//
// Created by eciuc on 6/12/2024.
//

#include "Node.h"
#include "OccupiedNode.h"

Node *Node::new_state_on_move(Capturer &cap, Node &node) {
    return new OccupiedNode(node, cap);
}

Node *Node::new_state_on_removed(Capturer &, Node &) {
    throw MovedFromEmptyTile("This tile has no piece to move");
}

bool Node::point_inside(float xc, float yc) {
    Point b=Point(xc,yc);
    Line l=Line(*dynamic_cast<Point*>(this),b);
    if(l.get_length()<=rad)
    {
        return true;
    }
    return false;
}

std::vector<int> &Node::get_neighbours() {
    return next_index;
}

int Node::get_index_in_graph() const {
    return index;
}

void Node::add_edge_by_index(int j) {
    next_index.push_back(j);
}

void Node::set_rad(float other_rad) {
    rad=other_rad;
}

/*void Node::change_color(sf::Color new_color) const {
    Drawables::change_circle_color(index,new_color);
}*/

bool Node::is_occupied_by(Capturer &) {
    return false;
}

void Node::update_color() {
    Drawables::change_circle_color(index,sf::Color::White);
    std::cout<<"White";
}
