#include <iostream>
#include "data/flight.h"
#include "data/reader.h"
//#include <ncurses.h>
//#include "user/user.h"

void getch() { // this is for linux-clion to prevent immediately closing after work is done.
    std::cin.get();
    std::string a;
    getline(std::cin, a);
}

int main() {
    Reader reader;
    std::cout << "input amount of flight: ";
    int n = 0;
    std::cin >> n;
    reader.AddSeveralFlights(n);

    reader.ShowFlights(reader.ReadFromFile());


    const std::string kMenu = "\n1 - Flight\n2 - Airplane\n3 - Date\n4 - Tickets\n5 - Full Flight\t your choice: ";
    std::cout << kMenu;
    int choice = 0;
    std::cin >> choice;
    Parameter parameter;

    if (choice == 1) {
        parameter = Parameter::Flight;
    } else if (choice == 2) {
        parameter = Parameter::Airplane;
    } else if (choice == 3) {
        parameter = Parameter::Date;
    } else if (choice == 4) {
        parameter = Parameter::Tickets;
    } else {
        parameter = Parameter::FullFlight;
    }

    auto vec = reader.Search(parameter);
    reader.ShowFlights(vec);

    int x = 0;
    std::cout << "Want to show ? 1 - y, else - n";
    std::cin >> x;
    if (x == 1) {
        reader.ShowFlights(reader.ReadFromFile());
    }

    getch();

    return 0;
}

/*
std::cout << '\n';

    {
        auto vec = reader.ReadFromFile();
        int position = 0;
        for (auto &i: vec) {
            ++position;
            std::cout << '#' << position << ' ' << std::left << i << '\n';
        }
    }

    int num = 0;
    std::cout << "Input flight you want to delete: ";
    std::cin >> num;
    reader.DeleteFlight(num);

    int x = 0;
    std::cout << "Want to show ? 1 - y, else - n";
    std::cin >> x;
    if (x == 1) {
        {
            auto vec = reader.ReadFromFile();
            int position = 0;
            for (auto &i: vec) {
                ++position;
                std::cout << '#' << position << ' ' << std::left << i << '\n';
            }
        }
    }
 */
