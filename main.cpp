#include "core.h"
#include "reader/reader.h"

int main() {
    std::vector<User> accounts;
    std::vector<Flight> flights;
    ReadFiles(accounts, flights);

    Core(accounts, flights);

    return 0;
}
