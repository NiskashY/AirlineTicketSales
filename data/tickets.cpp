#include "tickets.h"

std::istream &operator>>(std::istream &in, Tickets &tickets) {
    if (typeid(in) == typeid(std::ifstream)) {
        in >> tickets.available_in_business_ >> tickets.price_of_business_ >> tickets.available_in_economy_ >> tickets.price_of_economy_;
    }
    else {
        // TODO: VALIDATION
        std::cout << "Input available seats in business class: ";
        CheckNum(in, tickets.available_in_business_);
        std::cout << "Input price of business class: ";
        CheckNum(in, tickets.price_of_business_);
        std::cout << "Input available seats in economy class: ";
        CheckNum(in, tickets.available_in_economy_);
        std::cout << "Input price of economy class: ";
        CheckNum(in, tickets.price_of_economy_);
    }
    return in;
}

bool operator==(const Tickets &lhs, const Tickets &rhs) {
    return std::tie(lhs.price_of_economy_, lhs.available_in_economy_, lhs.price_of_business_, lhs.available_in_business_)
           == std::tie(rhs.price_of_economy_, rhs.available_in_economy_, rhs.price_of_business_, rhs.available_in_business_);
}
