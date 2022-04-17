#include "flight.h"

const std::string &Flight::getFlightNumber() const {
    return flight_number_;
}

const std::string &Flight::getDestination() const {
    return destination_;
}

void Flight::setFlightNumber(const std::string &flightNumber) {
    flight_number_ = flightNumber;
}

void Flight::setDestination(const std::string &destination) {
    destination_ = destination;
}


Flight CreateFlight() {
    Airplane airplane;
    Date date;
    Tickets tickets;
    std::string destination;
    std::string flight_number;

    // TODO: Add check of input
    std::cout << "Input destination: ";
    std::cin >> destination;
    std::cout << "Input flight number: ";
    std::cin >> flight_number;

    std::cin >> airplane >> date >> tickets;

    return {flight_number, destination, airplane, date, tickets};
}
