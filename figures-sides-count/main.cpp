#include "Figure.h"
#include "iostream"

void PrintFigure(const Figure &f) {
    std::cout << f.GetName() << ": " << f.GetSidesCount() << std::endl;
}


int main() {
    Figure figures[3];
    TriangleAbstract triangles[5];
    Quadrangle quadrangles[4];

    std::cout << "Количество сторон:" << std::endl;

    for(const auto &fig: figures) {
        PrintFigure(fig);
    }

    for(const auto &fig: triangles) {
        PrintFigure(fig);
    }

    for(const auto &fig: quadrangles) {
        PrintFigure(fig);
    }
}