//
// Created by eciuc on 6/12/2024.
//

#ifndef OOP_MAPGENERATOR_H
#define OOP_MAPGENERATOR_H


#include <cstdlib>
#include <vector>
#include "Node.h"
#include "LineDecorator.h"
#include "Drawables.h"

class MapGenerator {
    [[maybe_unused]] const int nr_nodes,minrad;
    Capturer player,enemy;
    std::vector<Node*> v;
    std::vector<LineDecorator> edges;
public:
    explicit MapGenerator(unsigned int max_x,unsigned int max_y,int nr_nodes = 50,int minradc = 10);
    bool action(float x,float y);
};


#endif //OOP_MAPGENERATOR_H
