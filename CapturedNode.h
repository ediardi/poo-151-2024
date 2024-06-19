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

    bool is_occupied_by(Capturer &cap) override{
        return false;
    }
    Capturer& get_capturer()
    {
        return capturer;
    }
    Node * new_state_on_move(Capturer &cap, Node &node) override;
    Node * new_state_on_removed(Capturer &cap, Node &node) override;
    void update_color() override{
        Drawables::change_circle_color(index,sf::Color::Yellow);
    }
};


#endif //OOP_CAPTUREDNODE_H
