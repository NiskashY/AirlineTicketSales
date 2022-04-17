#include "date.h"

const std::string &Date::getDepartureDate() const {
    return departure_date_;
}

const std::string &Date::getArrivalTime() const {
    return arrival_time_;
}

const std::string &Date::getTime() const {
    return departure_time_;
}

std::istream &operator>>(std::istream &in, Date &date) {
    std::cout << "Input flight departure date: ";
    CheckNum(in, date.departure_date_);
    std::cout << "Input flight departure time: ";
    CheckNum(in, date.departure_time_);
    std::cout << "Input flight arrival time: ";
    CheckNum(in, date.arrival_time_);
    return in;
}

void Date::setDepartureDate(const std::string &departureDate) {
    departure_date_ = departureDate;
}

void Date::setDepartureTime(const std::string &departureTime) {
    departure_time_ = departureTime;
}

void Date::setArrivalTime(const std::string &arrivalTime) {
    arrival_time_ = arrivalTime;
}
