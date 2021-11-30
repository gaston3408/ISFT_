#include "Figure.hpp"

const float pi = 3.14;

class Circle: public Figure
{
private:
    float x;
public:
    Circle(float x){
        this->x = x;
    };
    float getPerimeter(){
        return (pi * x) * 2;
    };
    float getArea(){
        return ( x * x ) * pi;
    };
    ~Circle(){};
};