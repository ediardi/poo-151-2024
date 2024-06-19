//
// Created by eciuc on 4/9/2024.
//

#ifndef OOP_LINE_H
#define OOP_LINE_H

#include "Point.h"

class Line {
    Point a,b;
public:
    Point startpoint();
    Point endpoint();
    Line(Point a1,Point b1);
    [[nodiscard]] float get_length() const;
    friend std::ostream& operator<<(std::ostream& os, const Line& line);
};


#endif //OOP_LINE_H
