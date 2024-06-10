//
// Created by eciuc on 6/3/2024.
//

#ifndef OOP_PLAYERTRIANGLE_H
#define OOP_PLAYERTRIANGLE_H

#include "Triangle.h"
#include "GeometricError.h"

class PlayerTriangle : public Triangle {
public:
    [[nodiscard]] bool is_inside_circle(Point origin,float other_radius) const;
    PlayerTriangle();

    [[nodiscard]] float get_area() const override;
};


#endif //OOP_PLAYERTRIANGLE_H
