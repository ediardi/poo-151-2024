//
// Created by eciuc on 4/15/2024.
//

#ifndef OOP_GAMESTATEMANAGER_H
#define OOP_GAMESTATEMANAGER_H


#include <fstream>
#include "Triangle.h"

class GameStateManager {
    std::ifstream fin;
    int n,index,points=0, frames_to_show_results=0;
    const int results_max_frames = 90;
    void next_level();
    void evaluate();
    bool replaylevel=false;
    Triangle *challange_triangle= nullptr;
    Triangle *candidate_triangle= nullptr;
    sf::Color highligh_color;
    sf::Color opposite(sf::Color color);
    sf::CircleShape *draw_circle_reference;
    ColoredTriangle *draw_challenge_triangle_reference;
    ColoredTriangle *draw_candidate_triangle_reference;
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
    bool is_in_circle();

    bool triangles_do_not_intersect();
};


#endif //OOP_GAMESTATEMANAGER_H
