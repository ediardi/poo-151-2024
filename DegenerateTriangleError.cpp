//
// Created by eciuc on 6/3/2024.
//

#include "DegenerateTriangleError.h"

DegenerateTriangleError::DegenerateTriangleError(const std::string &message) :
        std::runtime_error("Triunghi degenerat:" + message) {}
