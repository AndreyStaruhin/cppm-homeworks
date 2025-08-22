#include "iostream"
#include "Counter.h"

int main() {
    Counter cnt;
    while (true) {
        std::string choice;
        std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
        std::cin >> choice;
        if(choice == "да") {
            int init;;
            std::cout << "Введите начальное значение счётчика: ";
            std::cin >> init;
            cnt = Counter {init};
        }
        else if(choice == "нет") {
            break;
        }
    }

    while(true) {
        std::string command;
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        if(command == "+") {
            cnt.increment();
        } else if(command == "-") {
            cnt.decrement();
        } else if(command == "=") {
            std::cout << cnt.getValue() << std::endl;
        }
        else if(command == "x") {
            return 0;
        }
        else {
            std::cout << "Неверная команда" << std::endl;
        }
    }
}
