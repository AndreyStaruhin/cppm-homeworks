#include "iostream"
#include "Calculator.h"

void CalculateNumbers(Calculator calc) {
    int num1;
    int num2;
    std::cout << "Введите num1: ";
    std::cin >> num1;
    calc.set_num1(num1);
    std::cout << "Введите num2: ";
    std::cin >> num2;
    calc.set_num2(num2);
    std::cout << "num1 + num2 = " << calc.add() << std::endl;
    std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
    std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
    std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
    std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
    std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
}

int main() {

    Calculator calc;
    while (true) {
        CalculateNumbers( calc);
    }
}