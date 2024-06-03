//
// Created by eciuc on 6/3/2024.
//

#include "DegenerateTriangleError.h"
#include <string>

DegenerateTriangleError::DegenerateTriangleError(const std::string &message) :
        std::runtime_error(std::string ("Triunghi degenerat:") + message) {}
