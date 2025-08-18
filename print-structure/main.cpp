#include <string>
#include "iostream"

struct Address {
    std::string city;
    std::string street;
    int houseNumber {0};
    int apartmentNumber {0};
    int postalCode {0};
};


void printAddress(const Address& addr) {
    std::cout << "Город: " << addr.city << "\n"
              << "Улица: " << addr.street << "\n"
              << "Номер дома: " << addr.houseNumber << "\n"
              << "Номер квартиры: " << addr.apartmentNumber << "\n"
              << "Индекс: " << addr.postalCode << "\n\n";
}

int main() {
    Address addr1 = {
            "Новосибирск",
            "Проспект Дзержинского",
            25,
            12,
            119002
    };

    Address addr2 = {
            "Санкт-Петербург",
            "Невский проспект",
            15,
            34,
            191186
    };

    printAddress(addr1);
    printAddress(addr2);
}
