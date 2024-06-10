//
// Created by eciuc on 6/3/2024.
//

#include "GeometricError.h"
#include <string>

DegenerateTriangle::DegenerateTriangle(const std::string &message) :
        GeometricError(std::string ("Triunghi degenerat:") + message) {}

DoubleClick::DoubleClick(const std::string &message) :
        GeometricError(message) {}

CannotProcessClick::CannotProcessClick(const std::string &message) :
        GeometricError(message) {}
