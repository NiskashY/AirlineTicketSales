#include "core.h"
#include "reader/reader.h"

void ReadFiles(std::vector<User>& accounts, std::vector<Flight>& flights);

int main() {
    std::vector<User> accounts;
    std::vector<Flight> flights;
    ReadFiles(accounts, flights);

    Core(accounts, flights);

    return 0;
}

void ReadFiles(std::vector<User>& accounts, std::vector<Flight>& flights) {
    Reader accountsReader(ALL_USER_ACCOUNTS);
    Reader flightsReader(FLIGHTS_DATABASE);

    accountsReader.ReadFromFile(accounts);
    flightsReader.ReadFromFile(flights);

    if (accounts.empty()) {
        // if in accounts file empty - add Main Admin
        User main_admin("admin", GenerateHashPassword("adminadmin"), 3);
        accountsReader.AddObject(main_admin);
        accounts.push_back(main_admin);
    }
}
