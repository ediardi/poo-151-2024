//
// Created by eciuc on 6/18/2024.
//

#include "CapturedNode.h"
#include "OccupiedNode.h"

Node *CapturedNode::new_state_on_move(Capturer &cap, Node &node) {
    auto& this_node=dynamic_cast<CapturedNode&>(node);
    return new OccupiedNode(this_node,cap);
}

Node *CapturedNode::new_state_on_removed(Capturer &cap, Node &node) {
    return Node::new_state_on_removed(cap, node);
}
