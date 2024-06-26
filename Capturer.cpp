//
// Created by eciuc on 6/18/2024.
//

#include "Capturer.h"
#include "Node.h"
#include "GameStateError.h"

bool Capturer::move(Node &node, std::vector<Node *> &graph) {
    //validate move
    if(current_pos==-1)
    {
        try {
            graph[node.get_index_in_graph()] = node.new_state_on_move(*this,node);
            graph[node.get_index_in_graph()]->update_color();
            current_pos=node.get_index_in_graph();
            Drawables::move_pawn(getId(), *graph[node.get_index_in_graph()]);
            return true;
        }
        catch(AlreadyOccupiedError &err){
            std::cout<<err.what()<<std::endl;
            return false;
        }
    }

    const std::vector<int>& neighbours= node.get_neighbours();
    int valid= -1;
    for(auto index:neighbours)
    {
        auto neigh= graph[index];
        if(neigh->is_occupied_by(*this))
        {
            valid=neigh->get_index_in_graph();
        }
    }

    if(valid>=0) {
        try{
            graph[node.get_index_in_graph()] = node.new_state_on_move(*this,node);
            graph[node.get_index_in_graph()]->update_color();
            current_pos=node.get_index_in_graph();
            Drawables::move_pawn(getId(), *graph[node.get_index_in_graph()]);
            Node* temp=graph[valid];
            graph[valid] = temp->new_state_on_removed(*this,*temp);
            graph[valid]->update_color();
            return true;
        }
        catch(AlreadyOccupiedError &err){
            std::cout<<err.what()<<std::endl;
            return false;
        }
        catch(MovedFromEmptyTile &err){
            std::cout<<err.what()<<std::endl;
            return false;
        }
    }
    return false;
}


const sf::Color &Capturer::getCapturedCol() const {
    return captured_col;
}

/*const sf::Color &Capturer::getOccupiedCol() const {
    return occupied_col;
}*/

int Capturer::getId() const {
    return id;
}

Capturer::Capturer(sf::Color cap_col, sf::Color occ_col)
        :id(id_c),current_pos(-1),captured_col(cap_col),occupied_col(occ_col){
    id_c++;
    Drawables::add(sf::Vertex(),occupied_col);
}
