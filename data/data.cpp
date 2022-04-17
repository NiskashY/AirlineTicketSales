#include "data.h"

void AddFlight(const Flight &flight) {
    const std::string kFileName = "flights_database.txt";
    std::ofstream file(kFileName, std::ios::app);

    if (!file.is_open()) {
        std::cerr << '\n' << "NOT OPENED" << '\n';
    }

    file << flight << '\n';
    file.close();
}

void AddSeveralFlights(int &amount) {
    const std::string kSuggest = "Input information about flight: ";
    for (int i = 1; i <= amount; ++i) {
        std::cout << "#" << i << ' ' << kSuggest << '\n';
        AddFlight(CreateFlight());
    }
}

std::vector<Flight> ReadFromFile(const std::string& kFileName) {
    std::ifstream out (kFileName, std::ios::in);
    std::vector<Flight> all_available_flights;

    while(!out.eof()) {
        Flight tmp;
        out >> tmp;
        all_available_flights.push_back(tmp);
    }

    out.close();

    return all_available_flights;
}