//
// Created by eciuc on 4/15/2024.
//

#ifndef OOP_GAMESTATEMANAGER_H
#define OOP_GAMESTATEMANAGER_H


#include <fstream>
#include "MapGenerator.h"

class GameStateManager {
    std::ifstream fin;
    MapGenerator& map;
    int n{},index,points=0;
    //int frames_to_show_results=0;
    const int results_max_frames = 45;
    //void next_level();
    //void evaluate();
    //bool replay_level=false;
    enum State{
        awaiting_point,
        showing_result,
        click_to_continue,
        game_end
    } state=awaiting_point;
public:
    explicit GameStateManager(MapGenerator &map);
    ~GameStateManager();
    void handle_click(float x, float y);
    bool has_ended();
};


#endif //OOP_GAMESTATEMANAGER_H
