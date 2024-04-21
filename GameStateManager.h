//
// Created by eciuc on 4/15/2024.
//

#ifndef OOP_GAMESTATEMANAGER_H
#define OOP_GAMESTATEMANAGER_H


#include <fstream>
#include "Triangle.h"

class GameStateManager {
    std::ifstream fin;
    int n{},index,points=0, frames_to_show_results=0;
    const int results_max_frames = 45;
    void next_level();
    void evaluate();
    bool replay_level=false;
    Triangle challenge_triangle;
    Triangle candidate_triangle;
    sf::Color highlight_color;
    sf::Color opposite(sf::Color color) const;
    int draw_circle_index = -1;
    int draw_challenge_triangle_index = -1;
    int draw_candidate_triangle_index = -1;
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
    bool is_in_circle() const;
    bool triangles_do_not_intersect() const;
};


#endif //OOP_GAMESTATEMANAGER_H
