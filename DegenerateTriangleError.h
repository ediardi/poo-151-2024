//
// Created by eciuc on 6/3/2024.
//

#ifndef OOP_DEGENERATETRIANGLEERROR_H
#define OOP_DEGENERATETRIANGLEERROR_H


#include <stdexcept>

class DegenerateTriangleError : public std::runtime_error {
    using std::runtime_error::runtime_error;
public:
    explicit DegenerateTriangleError(const std::string &message);
};




#endif //OOP_DEGENERATETRIANGLEERROR_H
