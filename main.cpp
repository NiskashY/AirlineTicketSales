#include <iostream>
#include "core.h"

#define TO_ROW(num) (std::cout << "\033[" + std::to_string(num) + "G")
#define CLEAR_LINE() (std::cout << "\033[2K")
#define UP_LINE() (std::cout << "\033[1A")


int main() {
    Reader accountsReader(ALL_USER_ACCOUNTS);
    Reader flightsReader(FLIGHTS_DATABASE);

    std::vector<User> accounts;
    std::vector<Flight> flights;

    accountsReader.ReadFromFile(accounts);
    flightsReader.ReadFromFile(flights);

    Core(accounts, flights);

    getch();
    return 0;
}
