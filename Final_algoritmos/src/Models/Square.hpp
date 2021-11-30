#include "Figure.hpp"

class Square: public Figure
{
private:
    float x;
public:
    Square(float x){
        this->x = x;
    };
    float getPerimeter(){
        return 4 * this->x;
    };
    float getArea(){
        return (this->x * this->x);
    };
    ~Square(){};
};