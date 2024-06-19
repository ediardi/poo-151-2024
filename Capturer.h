//
// Created by eciuc on 6/18/2024.
//

#ifndef OOP_CAPTURER_H
#define OOP_CAPTURER_H


#include <vector>

class Node;

class Capturer {
    int current_pos;
public:
    Capturer():current_pos(-1){}
    bool move(Node& node, std::vector<Node *> &graph);
};


#endif //OOP_CAPTURER_H
