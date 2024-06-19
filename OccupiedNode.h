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


    bool is_occupied_by(Capturer &cap) override{
        if(&occupier==&cap)
        {
            return true;
        }
        return false;
    }
    Node * new_state_on_move(Capturer &, Node &) override{
        throw AlreadyOccupiedError("Tile already occupied");
    }
    Node * new_state_on_removed(Capturer &, Node &node) override{
        auto upnode=dynamic_cast<CapturedNode*>(&node);
        auto this_node= new CapturedNode(*upnode);
        return this_node;
    }
    void update_color() override{
        Drawables::change_circle_color(index,get_capturer().getCapturedCol());
    }
};


#endif //OOP_OCCUPIEDNODE_H
