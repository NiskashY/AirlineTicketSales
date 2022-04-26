#include <iostream>
#include "data/flight.h"
#include "data/ticket_purchase.h"
#include "reader/reader.h"
//#include <ncurses.h>
#include "user/standard_user.h"
#include "user/admin.h"
void getch() { // this is for linux-clion to prevent immediately closing after work is done.
    std::cin.get();
    std::string a;
    getline(std::cin, a);
}

int main() {
    Admin admin;
    StandardUser user;

//    user.View();
//    user.BuyTickets();
//    ShowFlights(user.Search(Parameter::Flight));

    std::cout << "\n\n----------------------\n\n";
    admin.ViewFlights();
//    admin.BuyTickets();
//    admin.AddFlights();
//    ShowFlights(admin.SearchFlights(Parameter::Date));
//
//    user.SortFlights(Parameter::Airplane);
    admin.DeleteFlights();

    ShowFlights();
    getch();
    return 0;
}

/*
    reader.DeleteObject({1, 2}, flights);

    std::cout << "INPUT time: ";
    std::string tmp = InputTime(std::cin, "departure time");
    std::cout << "time: " << tmp << '\n';

    reader.Edit(pos, flights);
    std::cout << "input amount of flight: ";
    int n = 0;1
    std::cin >> n;
    std::vector<Flight> vec(n);
    for (auto& i : vec) {
        std::cin >> i;
    }
    reader.AddSeveralObjects(vec);

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

    auto a = Search(parameter);
    ShowFlights(a);
    std::cout << "\n\n";
    ShowFlights();
    int x = 0;
    std::cout << "Want to show ? 1 - y, else - n";
    std::cin >> x;
    if (x == 1) {
        std::vector<Flight> data_to_show;
        reader.ReadFromFile(data_to_show);
        ShowFlights(data_to_show);
    }

     const std::string kMenu = "\n1 - Flight\n2 - Airplane\n3 - Date\n4 - Tickets\n5 - Full Flight\t your choice: ";

    int choice = 0;

    while (true) {
        std::cout << kMenu;
        std::cin >> choice;
        switch (choice) {
            case 1:
            default: {
                Sort(Parameter::Flight);
                break;
            }
            case 2: {
                Sort(Parameter::Airplane);
                break;
            }
            case 3: {
                Sort(Parameter::Date);
                break;
            }
            case 4: {
                Sort(Parameter::Tickets);
                break;
            }
        }
        std::cout << "\n\n\n";
        ShowFlights();
    }
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
