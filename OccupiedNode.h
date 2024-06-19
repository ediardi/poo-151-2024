//
// Created by eciuc on 6/18/2024.
//

#ifndef OOP_OCCUPIEDNODE_H
#define OOP_OCCUPIEDNODE_H

#include "CapturedNode.h"
#include "GameStateError.h"

class Node;
class Capturer;

class OccupiedNode: public CapturedNode {
    Capturer& occupier;
public:
    explicit OccupiedNode(Node& node, Capturer& occupier) : CapturedNode(node,occupier), occupier(occupier) {};
    explicit OccupiedNode(CapturedNode& node, Capturer& occupier) : CapturedNode(node), occupier(occupier) {};


    bool is_occupied_by(Capturer &cap) override;
    Node * new_state_on_move(Capturer &, Node &) override;
    Node * new_state_on_removed(Capturer &, Node &node) override;
    void update_color() override;
};


#endif //OOP_OCCUPIEDNODE_H
