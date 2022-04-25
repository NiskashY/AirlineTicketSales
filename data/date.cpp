#include "date.h"

std::istream &operator>>(std::istream &in, Date &date) {
    if (typeid(in) == typeid(std::ifstream)) { // input is file - transfer information into files without validation.
        in >> date.departure_date_ >> date.departure_time_ >> date.arrival_time_;
    } else {
        date.departure_date_ = InputDate(in);
        date.departure_time_ = InputTime(in, "departure time");
        date.arrival_time_ = InputTime(in, "arrival time");
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Date &date) {
    const int kTimeLength = 8;
    const int kDateLength = 13;

    out << std::setw(kDateLength) << date.departure_date_
        << std::setw(kTimeLength) << date.departure_time_
        << std::setw(kTimeLength) << date.arrival_time_;
    return out;
}

bool operator==(const Date &lhs, const Date &rhs) {
    return std::tie(lhs.departure_time_, lhs.departure_date_, lhs.arrival_time_)
           == std::tie(rhs.departure_time_, rhs.departure_date_, rhs.arrival_time_);
}

bool operator<(const Date &lhs, const Date &rhs) {
    return std::tie(lhs.departure_date_, lhs.departure_time_, lhs.arrival_time_)
           < std::tie(rhs.departure_date_, rhs.departure_time_, rhs.arrival_time_);
}
