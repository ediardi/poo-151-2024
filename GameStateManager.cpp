//
// Created by eciuc on 4/15/2024.
//

#include <iostream>
#include "Stopwatch.h"
#include "GameStateManager.h"
#include "Drawables.h"
#include "Point.h"

GameStateManager::GameStateManager(MapGenerator &map):fin("levels.txt"), map(map) {
    fin>>n;
    index=0;
}

void GameStateManager::handle_click(float x, float y) {
    Stopwatch::discard_double_action();
    switch (state) {
        case awaiting_point:
        {
            map.action(x,y);
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

/*
void GameStateManager::evaluate() {
    state=showing_result;
}*/

