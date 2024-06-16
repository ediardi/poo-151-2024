//
// Created by eciuc on 6/12/2024.
//

#ifndef OOP_NODE_H
#define OOP_NODE_H


#include "Point.h"

class Node : public Point {
    std::vector<int> next_index;
public:
    explicit Node(Point p):Point(p){}
    void add_edge_by_index(int j)
    {
        next_index.push_back(j);
    }
};


#endif //OOP_NODE_H
