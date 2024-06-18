//
// Created by eciuc on 6/18/2024.
//

#ifndef OOP_CAPTURER_H
#define OOP_CAPTURER_H


#include "Node.h"

class Capturer {
public:
    void move(Node& node,std::vector<Node>& graph){
        //validate move
        std::vector<int>& neighbours= node.get_neighbours();
        for(auto index:neighbours)
        {
            auto neigh= graph[index];
            if(neigh.is_occupied_by(this))
            {
            }
        }
        //get from where
        //

    };
};


#endif //OOP_CAPTURER_H
