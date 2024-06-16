//
// Created by eciuc on 4/15/2024.
//

#include <iostream>
#include "Stopwatch.h"
#include "GameStateManager.h"
#include "Drawables.h"
#include "Point.h"

GameStateManager::GameStateManager():fin("levels.txt") {
    fin>>n;
    index=0;
    std::cout << "This game has " << n << " levels in which you have to make a triangle of largest area possible that is within the circumscribed circle of the given triangle and does not intersect it" << std::endl;
    std::cout << "To pass each level you have to have an area of at least 75% of the theoretical maximum area" << std::endl;
}

void GameStateManager::handle_click(float x, float y) {
    Stopwatch::discard_double_action();
    ///remove later
    x=x+y;
    ///
    switch (state) {
        case awaiting_point:
        {
            break;
        }
        case click_to_continue:
        {
            break;
        }
        case showing_result:
        {
            throw CannotProcessClick("The game is currently processing results, click ignored");
        }
        case game_end:
        {
            break;
        }
    }
}

GameStateManager::~GameStateManager() {
    fin.close();
    Drawables::clear_all();
}

bool GameStateManager::has_ended() {
    if(index==n && state==game_end)
        return true;
    return false;
}

void GameStateManager::evaluate() {
    state=showing_result;
}



