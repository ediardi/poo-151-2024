//
// Created by eciuc on 6/3/2024.
//

#include "GameStateError.h"
#include <string>

AlreadyOccupiedError::AlreadyOccupiedError(const std::string &message) :
        GameStateError(std::string ("") + message) {}

DoubleClick::DoubleClick(const std::string &message) :
        GameStateError(message) {}

CannotProcessClick::CannotProcessClick(const std::string &message) :
        GameStateError(message) {}

MovedFromEmptyTile::MovedFromEmptyTile(const std::string &message) :
        GameStateError(message) {}
