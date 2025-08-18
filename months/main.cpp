#include <map>
#include <string>
#include <iostream>
enum class Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

const std::map<Month, std::string> russianMonthNames = {
        {Month::January,   "Январь"},
        {Month::February,  "Февраль"},
        {Month::March,     "Март"},
        {Month::April,     "Апрель"},
        {Month::May,       "Май"},
        {Month::June,      "Июнь"},
        {Month::July,      "Июль"},
        {Month::August,    "Август"},
        {Month::September, "Сентябрь"},
        {Month::October,   "Октябрь"},
        {Month::November,  "Ноябрь"},
        {Month::December,  "Декабрь"}
};

int main() {
    int month;
    while(true) {
        std::cout << "Введите номер месяца: ";
        std::cin >> month;
        if (month == 0){
            std::cout << "До свидания";
            break;
        }

        if(month < 0 || month > 12) {
            std::cout << "Неправильный номер!" << std::endl;
            continue;
        }

        std::cout << russianMonthNames.at(static_cast<Month>( month)) << std::endl;
    }
}