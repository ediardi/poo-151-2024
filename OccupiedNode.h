//
// Created by eciuc on 6/18/2024.
//

#ifndef OOP_OCCUPIEDNODE_H
#define OOP_OCCUPIEDNODE_H

#include "CapturedNode.h"
#include "Node.h"

class OccupiedNode: CapturedNode {
    Capturer& occupier;
public:
    explicit OccupiedNode(Node& node): CapturedNode(node){};
    bool can_be_occupied() override{
        return false;
    }

    bool is_occupied_by(Capturer &cap) override{
        if(occupier==cap)
        {
            return true;
        }

    }
};


#endif //OOP_OCCUPIEDNODE_H
