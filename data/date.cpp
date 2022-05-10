#include "date.h"

void ShowDate(const Date& date) {
    const auto &kDelim = "|";

    std::cout << std::setw(width::kDateLength) << date.departure_date_
              << std::setw(width::kDelim) << kDelim
              << std::setw(width::kTimeLength) << date.departure_time_
              << std::setw(width::kDelim) << kDelim
              << std::setw(width::kTimeLength) << date.arrival_time_
              << std::setw(width::kDelim) << kDelim;
}

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
    out << date.departure_date_ << ' ' << date.departure_time_ << ' ' << date.arrival_time_;
    return out;
}

bool operator==(const Date &lhs, const Date &rhs) {
    return lhs.departure_time_ == rhs.departure_time_ && lhs.arrival_time_ == rhs.arrival_time_ ||
           lhs.departure_date_ == rhs.departure_date_;
}

bool operator<(const Date &lhs, const Date &rhs) {
    return std::tie(lhs.departure_date_, lhs.departure_time_, lhs.arrival_time_)
           < std::tie(rhs.departure_date_, rhs.departure_time_, rhs.arrival_time_);
}
