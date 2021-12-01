#include "FigureList.hpp"
#include "Circle.hpp"
#include "Square.hpp"
#include "../Enums/FigureTypes.hpp"

#include <iostream>
using namespace std;

class FigureService
{
private: 
    Figure* getFigure(Options type, float x){
        switch (type)
        {
        case CIRCLE:
            return new Circle(x);
            break;
        case SQUARE:
            return new Square(x);
            break; 
        default:
            break;
        }
    };
public:
    FigureService(){};
    void getFigures(FigureList *figureList){
        float x;
        int type;


        while (type != 0)
        {
            cout << "0 - Salir"<< endl;
            cout << "1 - Circulo"<< endl;
            cout << "2 - Cuadrado"<< endl;
            cout << "Selecciona un tipo de figura: ";
            cin >> type;

            if(type != 0 && figureList->count < 3){

                if(type == 1){
                cout << "Ingresa el radio: ";
                cin >> x;
                }
                if(type == 2){
                cout << "Ingresa la medida del lado: ";
                cin >> x;
                }

                Options figureType = Options(type - 1);
                Figure* figure = this->getFigure(figureType, x);
                figureList->addFigure(figure);
            }
            else{
                cout << "No hay mas lugar par agregar"<< endl;
            }
        } 
    };

    void showFigures(FigureList *figureList){
        for (int i = 0; i < figureList->count; i++)
        {
            cout << "El perimetro de la figura " << i << " es " << figureList->figures[i]->getPerimeter() << endl;
            cout << "El area de la figura " << i << " es " << figureList->figures[i]->getArea() << endl;
        }
    };

    void deleteFigures(FigureList *figureList){
        for (int i = 0; i < figureList->count; i++)
        {
            delete figureList->figures[i];
        }
    };
    ~FigureService(){};
};