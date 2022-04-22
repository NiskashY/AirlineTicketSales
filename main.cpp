#include <iostream>
#include "data/flight.h"
#include "data/reader.h"
#include <ncurses.h>
//#include "user/user.h"

int main() {
    int n = 0;
    std::cin >> n;
    AddSeveralFlights(n);
    std::cout << '\n';
    auto vec = ReadFromFile();

    for (auto& i : vec) {
//        i.ShowFlight();
        std::cout << std::left << i << '\n';
    }


    return 0;
}
