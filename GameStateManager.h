//
// Created by eciuc on 4/15/2024.
//

#ifndef OOP_GAMESTATEMANAGER_H
#define OOP_GAMESTATEMANAGER_H


#include <fstream>
#include "Triangle.h"

class GameStateManager {
    std::ifstream fin;
    int n,index,points=0, results_frames=0;
    const int results_max_frames = 90;
    void next_level();
    void evaluate();
    Triangle *challange_triangle= nullptr;
    Triangle *candidate_triangle= nullptr;
    enum State{
        awaiting_point,
        showing_result,
        click_to_continue,
        game_end
    } state=awaiting_point;
public:
    GameStateManager();
    ~GameStateManager();
    void handle_click(float x, float y);
    bool has_ended();
    void frame_update();
};


#endif //OOP_GAMESTATEMANAGER_H
