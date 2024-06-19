//
// Created by eciuc on 6/12/2024.
//

#ifndef OOP_NODE_H
#define OOP_NODE_H


#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Drawables.h"
#include "CapturableEntity.h"
#include "Capturer.h"

class CapturedNode;
class OccupiedNode;

class Node : public Point, public CapturableEntity{
    std::vector<int> next_index;
    static inline float rad;
protected:
    int index;
public:
    [[nodiscard]] int get_index_in_graph() const{
        return index;
    }
    explicit Node(Point p,int i):Point(p),index(i){}
    void add_edge_by_index(int j)
    {
        next_index.push_back(j);
    }
    static void set_rad(float other_rad){
        rad=other_rad;
    }
    bool point_inside(float x, float y){
        Point b=Point(x,y);
        Line l=Line(*dynamic_cast<Point*>(this),b);
        if(l.get_length()<=rad)
        {
            return true;
        }
        return false;
    }
    std::vector<int>& get_neighbours(){
        return next_index;
    }
    void change_color(sf::Color new_color) const{
        Drawables::change_circle_color(index,new_color);
    }

    bool is_occupied_by(Capturer &) override{
        return false;
    }

    virtual Node* new_state_on_move(Capturer& cap,Node& node);
    virtual Node* new_state_on_removed(Capturer& cap,Node& node);
    virtual void update_color(){
        Drawables::change_circle_color(index,sf::Color::White);
        std::cout<<"White";
    }
    virtual ~Node()= default;
};


#endif //OOP_NODE_H
