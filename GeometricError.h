//
// Created by eciuc on 6/3/2024.
//

#ifndef OOP_GEOMETRICERROR_H
#define OOP_GEOMETRICERROR_H


#include <stdexcept>

class GeometricError : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class DegenerateTriangle : public GeometricError{
public:
    explicit DegenerateTriangle(const std::string &message) ;
};

class DoubleClick : public GeometricError{
public:
    explicit DoubleClick(const std::string &message);
};

class CannotProcessClick : public  GeometricError{
public:
    explicit CannotProcessClick(const std::string &message);
};






#endif //OOP_GEOMETRICERROR_H
