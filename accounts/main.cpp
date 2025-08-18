#include <string>
#include "map"
#include "iostream"

struct BankAccount {
    int accountNumber{};
    std::string ownerName;
    double balance{};
};

int main() {
    std::map<int, BankAccount> accounts;

    accounts[1] = {1, "Иван Иванов Иванович", 1500.75};
    accounts[2] = {2, "Петр Петров Петрович", 5000.50};
    accounts[3] = {3, "Сидоров Сидор Сидорович", 3200.25};

    while (true) {
        int number;
        std::cout << "Введите номер счёта(от 1 до 3) или 0 для выхода: " << std::endl;
        std::cin >> number;

        if(number == 0) {
            break;
        }
        auto account = accounts.find(number);

        if(account == accounts.end()) {
            std::cout << "Такого счёта не существует" << std::endl;
            continue;
        }

        auto accountData = account->second;
        std::cout << "Здравствуйте, " << account->second.ownerName << ". Ваш текущий баланс - " << account->second.balance << ". Введите новое значение баланса: " << std::endl;
        std::cin >> accountData.balance;

        std::cout << "Данные вашего счёта: " << accountData.ownerName << ", "
                  << accountData.accountNumber << ", " << accountData.balance << std::endl;
    }

}