#ifndef FIGURE_LIST_H
#define FIGURE_LIST_H

#include "Figure.hpp"
#include <iostream>
using namespace std;

const int MAX_LIMIT = 3; 

typedef Figure* ListFigures[MAX_LIMIT];

class FigureList
{
   
public:
    ListFigures figures;
    int count;
    FigureList(){};
    void addFigure(Figure *figure){
        if (this->count <= MAX_LIMIT)
        {
            this->figures[this->count] = figure;
            this->count++;
        }
        else
        {
            cout << "No se pueden agregar mas figuras." << endl;
        }      
    }
    ~FigureList(){};
};

#endif