#include "date.h"

const std::string &Date::getDepartureDate() const {
    return departure_date_;
}

const std::string &Date::getArrivalTime() const {
    return arrival_time_;
}

const std::string &Date::getTime() const {
    return time_;
}
