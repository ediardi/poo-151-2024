//
// Created by eciuc on 6/18/2024.
//

#include "OccupiedNode.h"

bool OccupiedNode::is_occupied_by(Capturer &cap) {
    if(&occupier==&cap)
    {
        return true;
    }
    return false;
}

Node *OccupiedNode::new_state_on_move(Capturer &, Node &) {
    throw AlreadyOccupiedError("Tile already occupied");
}

Node *OccupiedNode::new_state_on_removed(Capturer &, Node &node) {
    auto upnode=dynamic_cast<CapturedNode*>(&node);
    auto this_node= new CapturedNode(*upnode);
    return this_node;
}

void OccupiedNode::update_color() {
    Drawables::change_circle_color(index,get_capturer().getCapturedCol());
}
