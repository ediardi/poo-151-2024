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
