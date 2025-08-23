#ifndef CPPM_HOMEWORKS_CALCULATOR_H
#define CPPM_HOMEWORKS_CALCULATOR_H
#include "iostream"

class Calculator {
private:
    double num1;
    double num2;

public:
    Calculator();
    Calculator(double n1, double n2);

    double add() const;

    double multiply() const;

    double subtract_1_2() const;

    double subtract_2_1() const;

    double divide_1_2() const;

    double divide_2_1() const;

    bool set_num1(double num1);

    bool set_num2(double num2);
};

#endif //CPPM_HOMEWORKS_CALCULATOR_H
