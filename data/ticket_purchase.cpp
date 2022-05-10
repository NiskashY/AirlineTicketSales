#include "ticket_purchase.h"

bool isUserWantAnotherClass() {
    const auto &kNotEnoughSeats = "There are not enough seats available to buy so many tickets in this class.";
    const auto &kProposeAnotherClass = "Would you like to book a seat in another class?\n1 - YES\nelse - NO\tYour choice: ";

    std::cout << Paint(YELLOW, kNotEnoughSeats) << '\n' << Paint(YELLOW, kProposeAnotherClass);
    std::string answer;
    std::cin >> answer;
    return answer == "1";
}

bool BookTicket(Tickets &available_tickets, bool &isBooked) {
    const auto &kProposeClass = "Input type of ticket:\n1 - Economy\n2 - Business\nelse - back\tYour choice: ";
    std::cout << '\n' << kProposeClass;
    std::string type;
    std::cin >> type;

    if (type == "1") {
        int amount_of_tickets = InputAmountTickets();
        isBooked = BookEconomy(available_tickets, amount_of_tickets);
        if (!isBooked && isUserWantAnotherClass()) {
            isBooked = BookBusiness(available_tickets, amount_of_tickets);
        }
    } else if (type == "2") {
        int amount_of_tickets = InputAmountTickets();
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

