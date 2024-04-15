//
// Created by eciuc on 4/15/2024.
//

#include "GameStateManager.h"
#include "Drawables.h"
#include "Point.h"

GameStateManager::GameStateManager():fin("nivele.txt") {
    fin>>n;
    index=0;
    next_level();
}

void GameStateManager::handle_click(float x, float y) {
    switch (state) {
        case awaiting_point:
        {
            points++;
            switch (points) {
                case 1:
                {
                    candidate_triangle = new Triangle();
                    candidate_triangle->seta(Point(x,y));
                    break;
                }
                case 2:
                {
                    candidate_triangle->setb(Point(x,y));
                    break;
                }
                case 3:
                {
                    points = 0;
                    candidate_triangle->setc(Point(x,y));
                    evaluate();
                    break;
                }
            }
            break;
        }
        case click_to_continue:
        {
            next_level();
            break;
        }
        case showing_result:
        case game_end:
        {
            break;
        }
    }
}

GameStateManager::~GameStateManager() {
    fin.close();
}

void GameStateManager::next_level() {
    Drawables::clear_all();
    delete challange_triangle;
    delete candidate_triangle;
    if(index<n)
    {
        float x,y;
        fin>>x>>y;
        Point a(x,y);
        fin>>x>>y;
        Point b(x,y);
        fin>>x>>y;
        Point c(x,y);
        challange_triangle= new Triangle(a,b,c);
        challange_triangle->add_on_screen();
        index++;
        state=awaiting_point;
    }
    else
    {
        state=game_end;
    }
}

bool GameStateManager::has_ended() {
    if(index==n && state==game_end)
        return true;
    return false;
}

void GameStateManager::evaluate() {
    state=showing_result;
    results_frames=0;

    candidate_triangle->add_on_screen();
    challange_triangle->add_circumcircle_on_screen();
}

void GameStateManager::frame_update() {
    if(state==showing_result)
    {
        results_frames++;
        if (results_frames>results_max_frames)
        {
            state=click_to_continue;
        }
    }
}


