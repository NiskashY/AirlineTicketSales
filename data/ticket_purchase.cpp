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
        int amount_of_seats = InputAmountSeats();
        isBooked = BookEconomy(available_tickets, amount_of_seats);
        if (!isBooked && isUserWantAnotherClass()) {
            isBooked = BookBusiness(available_tickets, amount_of_seats);
        }
    } else if (type == "2") {
        int amount_of_seats = InputAmountSeats();
        isBooked = BookBusiness(available_tickets, amount_of_seats);
        if (!isBooked && isUserWantAnotherClass()) {
            isBooked = BookEconomy(available_tickets, amount_of_seats);
        }
    } else {
        return true;
    }

    if (!isBooked) {
        const auto& kNotEnough = "There are not enough seats on this flight!";
        std::cout << Paint(YELLOW, kNotEnough) << '\n';
        system("pause");
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

