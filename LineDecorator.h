//
// Created by eciuc on 6/16/2024.
//

#ifndef OOP_LINEDECORATOR_H
#define OOP_LINEDECORATOR_H


#include "Line.h"

class LineDecorator : public Line{
    int i,j;
public:
    [[nodiscard]] int getI() const {
        return i;
    }

    [[nodiscard]] int getJ() const {
        return j;
    }

    LineDecorator(int i,int j,Point a,Point b):Line(a,b),i(i), j(j){}
    bool operator<(LineDecorator& other){
        return this->get_length()<other.get_length();
    }
};


#endif //OOP_LINEDECORATOR_H
