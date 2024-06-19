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
    const int nr_nodes,minrad;
    Capturer player,enemy;
    std::vector<Node*> v;
    std::vector<LineDecorator> edges;
public:
    explicit MapGenerator(unsigned int max_x,unsigned int max_y,const int nr_nodes = 10,const int minrad = 15) :
                    nr_nodes(nr_nodes),minrad(minrad),player(Capturer(sf::Color::Cyan,sf::Color::Blue)),enemy(Capturer(sf::Color::Magenta,sf::Color::Red)){
        Node::set_rad(minrad);
        for (int i = 0; i < nr_nodes; ++i) {
            bool overlap=true;
            Point p;
            while(overlap) {
                overlap=false;
                int x = rand() % (max_x - 2 * minrad) + minrad;
                int y = rand() % (max_y - 2 * minrad) + minrad;
                //check for overlap
                p = Point(x, y);
                for (int j = 0; j < i; ++j) {
                    if (Line(*dynamic_cast<Point*>(v[j]), p).get_length() <= 2.0 * minrad) {
                        overlap=true;
                    }
                }
            }
            auto node = new Node(p,i);
            v.push_back(node);
            Drawables::add_node(p,minrad);
        }

        //add some lines
        for(int i=0;i<nr_nodes;i++)
        {
            for(int j=0;j<i;j++)
            {
                edges.emplace_back(i,j,*v[i],*v[j]);
            }
        }
        std::sort(edges.begin(),edges.end());

        std::vector<int>partition(nr_nodes,0);
        bool disconnected=true;
        for(unsigned int index=0; index < edges.size() && disconnected; index++)
        {
            auto l=edges[index];
            int i=l.getI();
            int j=l.getJ();
            v[i]->add_edge_by_index(j);
            v[j]->add_edge_by_index(i);
            Drawables::add_line(l);

            //if connected break
            if(partition[i]==0&&partition[j]==0)
            {
                partition[i]=index+1;
                partition[j]=index+1;
            }
            else
            {
                if(partition[i]==0)
                {
                    partition[i]=partition[j];
                }
                else
                if(partition[j]==0)
                {
                    partition[j]=partition[i];
                }
                else
                {
                    int part = partition[i];
                    for(int c=0;c<nr_nodes;c++)
                    {
                        if (partition[c]==part)
                            partition[c]=partition[j];
                    }
                }
            }
            disconnected= false;
            for(i=1;i<nr_nodes;i++)
            {
                 if(partition[i]!=partition[i-1])
                    disconnected=true;
            }
        }
    }
    bool action(float x,float y){
        for(Node* node:v)
        {
            if (node->point_inside(x,y))
            {
                //node.change_color(sf::Color::Yellow);
                if(player.move(*node,v)) {
                    //enemy move
                    //try to move to a random neigbour
                    Node* rand_node= v[rand()%nr_nodes];
                    while(!enemy.move(*rand_node,v))
                    {
                        rand_node= v[rand()%nr_nodes];
                    }
                }
                return true;
            }
        }
        return false;
    }
};


#endif //OOP_MAPGENERATOR_H
