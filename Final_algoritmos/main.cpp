#include "./src/Models/FigureList.hpp"
#include "./src/Models/FigureService.hpp"


int main()
{
    FigureList* figureList = new FigureList();
    FigureService* figureService = new FigureService();

    figureService->getFigures(figureList);
    figureService->showFigures(figureList);
    figureService->deleteFigures(figureList);

    delete figureList;
    delete figureService;
    return 0;
}
