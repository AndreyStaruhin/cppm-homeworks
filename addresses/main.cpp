#include <string>
#include <ostream>
#include <istream>
#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <algorithm>
struct Address {
    std::string Town{};
    std::string Street{};
    int House{};
    int ApartmentsNumber{};

    [[nodiscard]] std::string ToString() const {
        return Town + ", " + Street + ", " + std::to_string(House) + ", " + std::to_string(ApartmentsNumber);
    }

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
    for(int i = 0; i < count; i++) {
        Address address;
        input >> address.Town;
        input >> address.Street;
        input >> address.House;
        input >> address.ApartmentsNumber;
        addresses.push_back(address);
    }
    return  addresses;
}

int main() {
    auto exePath = std::filesystem::current_path().string();
    auto inFilePath = exePath + "/in.txt";

    std::ifstream inFile(inFilePath);
    std::vector<Address> addresses = ReadAddresses(inFile);
    std::sort(addresses.begin(), addresses.end(),[](Address &a1, Address &a2) { return a1.Town > a2.Town;});
    inFile.close();

    auto outFilePath = exePath + "/out.txt";
    std::ofstream outFile(outFilePath);
    PrintAddresses(outFile, addresses);
    outFile.close();
}