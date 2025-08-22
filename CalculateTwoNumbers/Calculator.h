#ifndef CPPM_HOMEWORKS_CALCULATOR_H
#define CPPM_HOMEWORKS_CALCULATOR_H
#include "iostream"

class Calculator {
private:
    double num1;
    double num2;

public:
    Calculator() : num1(0), num2(0) {}
    Calculator(double n1, double n2) : num1(n1), num2(n2) {}

    double add() const {
        return num1 + num2;
    }

    double multiply() const {
        return num1 * num2;
    }

    double subtract_1_2() const {
        return num1 - num2;
    }

    double subtract_2_1() const {
        return num2 - num1;
    }

    double divide_1_2() const {
        if (num2 == 0) {
            std::cerr << "Ошибка: деление на ноль!" << std::endl;
            return 0;
        }
        return num1 / num2;
    }

    double divide_2_1() const {
        if (num1 == 0) {
            std::cerr << "Ошибка: деление на ноль!" << std::endl;
            return 0;
        }
        return num2 / num1;
    }

    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        return false;
    }

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        return false;
    }
};

#endif //CPPM_HOMEWORKS_CALCULATOR_H
