#include "core.h"
#include "reader/reader.h"

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
