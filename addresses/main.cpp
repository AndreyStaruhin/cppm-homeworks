#include <string>
#include <ostream>
#include <istream>
#include <vector>

#include <fstream>
#include <filesystem>
#include <algorithm>
class Address {
public:
    Address(const std::string &town, const std::string &street, int house, int apartmentsNumber) : Town(town),
                                                                                                   Street(street),
                                                                                                   House(house),
                                                                                                   ApartmentsNumber(
                                                                                                           apartmentsNumber) {}

    const std::string &getTown() const {
        return Town;
    }

    const std::string &getStreet() const {
        return Street;
    }

    int getHouse() const {
        return House;
    }

    int getApartmentsNumber() const {
        return ApartmentsNumber;
    }

    [[nodiscard]] std::string ToString() const {
        return Town + ", " + Street + ", " + std::to_string(House) + ", " + std::to_string(ApartmentsNumber);
    }

private:
     std::string Town;
     std::string Street;
     int House;
     int ApartmentsNumber;
};

void PrintAddresses(std::ostream &output, const std::vector<Address> &addresses) {
    output << addresses.size() << std::endl;;
    for(auto address = addresses.rbegin(); address != addresses.rend(); address++) {
        if(address == addresses.rend()) { break;}
        auto data = address->ToString();
        output << address->ToString() << std::endl;
    }
}

std::vector<Address> ReadAddresses(std::istream &input) {
    int count;
    input >> count;
    std::vector<Address> addresses {};
    std::string town{};
    std::string street{};
    int house{};
    int apartmentsNumber{};

    for(int i = 0; i < count; i++) {
        input >> town;
        input >> street;
        input >> house;
        input >> apartmentsNumber;
        addresses.emplace_back(town, street, house, apartmentsNumber);
    }
    return  addresses;
}

int main() {
    auto exePath = std::filesystem::current_path().string();
    auto inFilePath = exePath + "/in.txt";

    std::ifstream inFile(inFilePath);
    std::vector<Address> addresses = ReadAddresses(inFile);
    std::sort(addresses.begin(), addresses.end(),[](Address &a1, Address &a2) { return a1.getTown() > a2.getTown();});
    inFile.close();

    auto outFilePath = exePath + "/out.txt";
    std::ofstream outFile(outFilePath);
    PrintAddresses(outFile, addresses);
    outFile.close();
}