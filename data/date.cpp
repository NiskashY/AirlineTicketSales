#include "date.h"

std::istream &operator>>(std::istream &in, Date &date) {
    if (typeid(in) == typeid(std::ifstream)) {
        in >> date.departure_date_ >> date.departure_time_ >> date.arrival_time_;
    }
    else {
        std::cout << "Input flight departure date: ";
        CheckNum(in, date.departure_date_);
        std::cout << "Input flight departure time: ";
        CheckNum(in, date.departure_time_);
        std::cout << "Input flight arrival time: ";
        CheckNum(in, date.arrival_time_);
    }
    return in;
}
