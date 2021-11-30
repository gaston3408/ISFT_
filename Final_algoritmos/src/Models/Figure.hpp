#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
private:
    float x;
public:
    Figure(){};
    virtual float getPerimeter() = 0;
    virtual float getArea() = 0;
    ~Figure(){};
};

#endif