//
// Created by eciuc on 6/18/2024.
//

#ifndef OOP_CAPTUREDNODE_H
#define OOP_CAPTUREDNODE_H

#include "Node.h"

class CapturedNode: Node {
    Capturer& capturer;
    void can_be_captured(Capturer &capturer) override{

    }
public:
    explicit CapturedNode(Node& node,Capturer& capturer1): Node(node), capturer(capturer1){};
    bool can_be_occupied() override{
        return true;
    }
    bool is_occupied_by(Capturer &cap) override{
        return false;
    }
};


#endif //OOP_CAPTUREDNODE_H
