//
// Created by eciuc on 6/18/2024.
//

#ifndef OOP_CAPTURABLEENTITY_H
#define OOP_CAPTURABLEENTITY_H

#include "Capturer.h"

class CapturableEntity {
public:
    //virtual void can_be_captured(Capturer&)=0;
    //virtual bool can_be_occupied(Node&)=0;
    virtual bool is_occupied_by(Capturer& cap)=0;
    //capture
};


#endif //OOP_CAPTURABLEENTITY_H
