#include "user.h"

void User::ViewFlights() const{
    ShowFlights();
}

void User::BuyTickets() {
    Reader reader("flights_database.txt");
    std::vector<Flight> flights;
    reader.ReadFromFile(flights);

    const auto &kSuccessBooked = "The Ticket was successfully booked!";
    const auto &kNotEnoughSeats = "There are not enough seats on this flight!\n"
                                  "1 - Choose another flight\nelse - exit\t Your choice: ";

    while(true) {
        int number = InputNumberOfFlight(flights.size());
        Tickets available_tickets = flights[number - 1].getTickets();

        bool isBooked = false;

        // if I need to exit;
        if (BookTicket(available_tickets, isBooked)) {
            return;
        }

        if (isBooked) {
            std::cout << kSuccessBooked << '\n';
            flights[number - 1].setTickets(available_tickets);
            reader.WriteIntoFile(flights);
            break;
        } else {
            std::cout << kNotEnoughSeats;
            std::string request;
            std::cin >> request;
            if (request != "1") {
                return;
            }
        }
    }
}

std::vector<Flight> User::SearchFlights(const Parameter& parameter) {
    const std::string kFileName_ = "flights_database.txt";
    std::ifstream in(kFileName_, std::ios::in);
    std::vector<Flight> matching_flights;

    // Parameter - what information we want to find
    switch (parameter) {
        case Parameter::Flight : {
            SearchPartFlight(in, matching_flights);
            break;
        }
        case Parameter::Airplane : {
            SearchAirplane(in, matching_flights);
            break;
        }
        case Parameter::Date: {
            SearchDate(in, matching_flights);
            break;
        }
        case Parameter::Tickets: {
            SearchTickets(in, matching_flights);
            break;
        }
        default : {
            SearchFullFlight(in, matching_flights);
        }
    }

    in.close();
    return matching_flights;
}

void User::SortFlights(const Parameter &parameter) {
    Reader reader("flights_database.txt");
    std::vector<Flight> data;
    reader.ReadFromFile(data);

    // Parameter - what information we want to find
    switch (parameter) {
        case Parameter::Flight : {
            std::sort(data.begin(), data.end());
            break;
        }
        case Parameter::Airplane : {
            std::sort(data.begin(), data.end(), [](const Flight& lhs, const Flight& rhs) {
                return lhs.getAirplane() < rhs.getAirplane();
            });
            break;
        }
        case Parameter::Date: {
            std::sort(data.begin(), data.end(), [](const Flight& lhs, const Flight& rhs) {
                return lhs.getDate() < rhs.getDate();
            });
            break;
        }
        case Parameter::Tickets: {
            std::sort(data.begin(), data.end(), [](const Flight& lhs, const Flight& rhs) {
                return lhs.getTickets() < rhs.getTickets();
            });
            break;
        }
        default : {
            return;
        }
    }
    reader.WriteIntoFile(data);
}
