//
// Created by eciuc on 6/3/2024.
//

#ifndef OOP_PLAYERTRIANGLE_H
#define OOP_PLAYERTRIANGLE_H

#include "Triangle.h"

class PlayerTriangle : public Triangle {
public:
    [[nodiscard]] bool is_inside_circle(Point origin,float other_radius) const;
};


#endif //OOP_PLAYERTRIANGLE_H
