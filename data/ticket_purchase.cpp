#include "ticket_purchase.h"

bool isUserWantAnotherClass() {
    const auto &kNotEnoughSeats = "There are not enough seats available to buy so many tickets in this class.";
    const auto &kProposeAnotherClass = "Would you like to book a seat in another class?\n1 - YES\nelse - NO\tYour choice: ";

    std::cout << kNotEnoughSeats << '\n' << kProposeAnotherClass;
    std::string answer;
    std::cin >> answer;
    return answer == "1";
}

void BuyTicket() {
    Reader reader("flights_database.txt");
    std::vector<Flight> flights;
    reader.ReadFromFile(flights);

    const auto &kSuccessBooked = "The Ticket was successfully booked!";
    const auto &kNotEnoughSeats = "There are not enough seats on this flight!\n"
                                  "1 - Choose another flight\nelse - exit\t Your choice";

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

bool BookTicket(Tickets &available_tickets, bool &isBooked) {
    const auto &kProposeClass = "Input type of ticket:\n1 - Economy\n2 - Business\nelse - exit\tYour choice: ";
    std::cout << kProposeClass;
    std::string type;
    std::cin >> type;

    int amount_of_tickets = InputAmountTickets();
    if (type == "1") {
        isBooked = BookEconomy(available_tickets, amount_of_tickets);
        if (!isBooked && isUserWantAnotherClass()) {
            isBooked = BookBusiness(available_tickets, amount_of_tickets);
        }
    } else if (type == "2") {
        isBooked = BookBusiness(available_tickets, amount_of_tickets);
        if (!isBooked && isUserWantAnotherClass()) {
            isBooked = BookEconomy(available_tickets, amount_of_tickets);
        }
    } else {
        return true;
    }

    return false;
}

bool BookBusiness(Tickets &available, const int &amount) {
    if (available.available_in_business_ >= amount) {
        available.available_in_business_ -= amount;
        return true;
    }
    return false;
}

bool BookEconomy(Tickets &available, const int &amount) {
    if (available.available_in_economy_ >= amount) {
        available.available_in_economy_ -= amount;
        return true;
    }
    return false;
}

