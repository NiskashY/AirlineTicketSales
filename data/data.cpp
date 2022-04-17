#include "data.h"

void AddFlight(const Flight &flight) {
    const std::string kFileName = "database.txt";
    std::ofstream file(kFileName, std::ios::binary | std::ios::out);

    if (!file.is_open()) {
        std::cerr << '\n' << "NOT OPENED" << '\n';
    }

    file.write((char *) &flight, sizeof(Flight));
    //file << "!!!!";
    file.close();
}

void AddSeveralFlights(int &amount) {
    const std::string kSuggest = "Input information about flight: ";
    for (int i = 1; i <= amount; ++i) {
        std::cout << "#" << i << ' ' << kSuggest << '\n';
        AddFlight(CreateFlight());
    }
}

void ReadFromFile(const std::string& kFileName = "database.txt") {

    // Файл database.txt находится в папке cmake-build-debug

}