//
// Created by eciuc on 6/16/2024.
//

#include "LineDecorator.h"

bool LineDecorator::operator<(LineDecorator &other) {
    return this->get_length()<other.get_length();
}

int LineDecorator::getJ() const {
    return j;
}

int LineDecorator::getI() const {
    return i;
}
