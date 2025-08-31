#ifndef CPPM_HOMEWORKS_FIGURE_H
#define CPPM_HOMEWORKS_FIGURE_H
#include <string>

class Figure {
public:
    virtual std::string GetName() const{
        return "Фигура";
    }
    virtual int GetSidesCount() const {
        return 0;
    }
};

class TriangleAbstract: public Figure {
public:
    std::string GetName() const override {
        return "Треугольник";
    }
    int GetSidesCount() const override {
        return 3;
    }
};

class Quadrangle: public Figure {

    std::string GetName() const override {
        return "Четырёхугольник";
    }

    int GetSidesCount() const override {
        return 4;
    }
};

#endif //CPPM_HOMEWORKS_FIGURE_H
