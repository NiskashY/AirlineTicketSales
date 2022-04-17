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

void Flight::ShowFlight() const {
    const int kTimeLength = 8;
    const int kNumbLength = 7;
    const int kDateLength = 13;
    const int kWordLength = 15;

    std::cout << std::fixed << std::left
              << std::setw(kWordLength) << destination_
              << std::setw(kNumbLength) << flight_number_
              << std::setw(kWordLength) << type_
              << std::setw(kNumbLength) << capacity_
              << std::setw(kDateLength) << departure_date_
              << std::setw(kTimeLength) << departure_time_
              << std::setw(kTimeLength) << arrival_time_
              << std::setw(kNumbLength) << available_in_business_
              << std::setw(kNumbLength) << price_of_business_
              << std::setw(kNumbLength) << available_in_economy_
              << std::setw(kNumbLength) << price_of_economy_ << '\n';

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

std::ostream &operator<<(std::ostream &out, const Flight &flight) {

    out << flight.destination_ << ' ' << flight.flight_number_ << ' ' << flight.type_ << ' ' << flight.capacity_ << ' '
              << flight.departure_date_ << ' ' << flight.departure_time_ << ' '  << flight.arrival_time_ << ' '
              << flight.available_in_business_ << ' ' << flight.price_of_business_ << ' ' << flight.available_in_economy_ << ' '
              << flight.price_of_economy_;

    return out;
}

std::istream &operator>>(std::istream &in, Flight &flight) {

    in >> flight.destination_ >> flight.flight_number_  >> flight.type_ >> flight.capacity_
        >> flight.departure_date_ >> flight.departure_time_ >> flight.arrival_time_ >> flight.available_in_business_
        >> flight.price_of_business_ >> flight.available_in_economy_ >> flight.price_of_economy_;

    return in;
}



