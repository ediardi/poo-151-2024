//
// Created by eciuc on 6/18/2024.
//

#ifndef OOP_CAPTUREDNODE_H
#define OOP_CAPTUREDNODE_H

#include "Node.h"

class OccupiedNode;

class CapturedNode: public Node {
    Capturer& capturer;
public:
    explicit CapturedNode(Node& node,Capturer& capturer1): Node(node), capturer(capturer1){};

    bool is_occupied_by(Capturer &) override;
    Capturer& get_capturer();
    Node * new_state_on_move(Capturer &cap, Node &node) override;
    Node * new_state_on_removed(Capturer &cap, Node &node) override;
    void update_color() override;
};


#endif //OOP_CAPTUREDNODE_H
