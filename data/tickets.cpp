#include "tickets.h"

std::istream &operator>>(std::istream &in, Tickets &tickets) {
    if (typeid(in) == typeid(std::ifstream)) {
        in >> tickets.available_in_business_ >> tickets.price_of_business_ >> tickets.available_in_economy_ >> tickets.price_of_economy_;
    }
    else {
        tickets.available_in_business_ = InputSeatsAmount(in, "business class", tickets.capacity);
        tickets.price_of_business_ = InputPrice(in, "business class");
        int free_seats_left = tickets.capacity - tickets.available_in_business_;
        tickets.available_in_economy_ = InputSeatsAmount(in, "economy class", free_seats_left);
        tickets.price_of_economy_ = InputPrice(in, "economy class");
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Tickets &tickets) {
    const int kNumbLength = 7;

    out << std::setw(kNumbLength) << tickets.available_in_business_
        << std::setw(kNumbLength) << tickets.price_of_business_
        << std::setw(kNumbLength) << tickets.available_in_economy_
        << std::setw(kNumbLength) << tickets.price_of_economy_;
    return out;
}

bool operator==(const Tickets &lhs, const Tickets &rhs) {
    return std::tie(lhs.price_of_economy_, lhs.available_in_economy_, lhs.price_of_business_, lhs.available_in_business_)
           == std::tie(rhs.price_of_economy_, rhs.available_in_economy_, rhs.price_of_business_, rhs.available_in_business_);
}

bool operator<(const Tickets &lhs, const Tickets &rhs) {
    return std::tie(lhs.available_in_business_, lhs.price_of_business_, lhs.available_in_economy_, lhs.price_of_economy_)
           < std::tie(rhs.available_in_business_, rhs.price_of_business_, rhs.available_in_economy_, rhs.price_of_economy_);
}
