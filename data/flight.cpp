#include "flight.h"

const std::string &Flight::getFlightNumber() const {
    return flight_number_;
}

const std::string &Flight::getDestination() const {
    return destination_;
}
