//
// Created by eciuc on 6/3/2024.
//

#ifndef OOP_GAMESTATEERROR_H
#define OOP_GAMESTATEERROR_H


#include <stdexcept>

class GameStateError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class AlreadyOccupiedError : public GameStateError{
public:
    explicit AlreadyOccupiedError(const std::string &message) ;
};

class MovedFromEmptyTile : public GameStateError{
public:
    explicit MovedFromEmptyTile(const std::string &message) ;
};

class DoubleClick : public GameStateError{
public:
    explicit DoubleClick(const std::string &message);
};

class CannotProcessClick : public  GameStateError{
public:
    explicit CannotProcessClick(const std::string &message);
};






#endif //OOP_GAMESTATEERROR_H
