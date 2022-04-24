#include "flight.h"

Flight CreateFlight() {
    Flight flight;
    std::cin >> flight;
    return flight;
}

std::ostream &operator<<(std::ostream &out, const Flight &flight) {
    const int kTimeLength = 8;
    const int kNumbLength = 7;
    const int kDateLength = 13;
    const int kWordLength = 16;

    // TODO: поправить и разбить на самолеты, дату и билеты
    out << std::fixed
        << std::setw(kWordLength) << flight.destination_
        << std::setw(kNumbLength) << flight.flight_number_
        << std::setw(kWordLength) << flight.airplane_.type_
        << std::setw(kNumbLength) << flight.airplane_.capacity_
        << std::setw(kDateLength) << flight.date_.departure_date_
        << std::setw(kTimeLength) << flight.date_.departure_time_
        << std::setw(kTimeLength) << flight.date_.arrival_time_
        << std::setw(kNumbLength) << flight.tickets_.available_in_business_
        << std::setw(kNumbLength) << flight.tickets_.price_of_business_
        << std::setw(kNumbLength) << flight.tickets_.available_in_economy_
        << std::setw(kNumbLength) << flight.tickets_.price_of_economy_;

    return out;
}

std::istream &operator>>(std::istream &in, Flight &flight) {
    // TODO: ADD VALIDATION!!!

    if (typeid(in) == typeid(std::ifstream)) {
        in >> flight.destination_ >> flight.flight_number_
           >> flight.airplane_ >> flight.date_ >> flight.tickets_;
    } else {
        const std::string kInputDestination = "Input Flight Destination: ";
        const std::string kInputNumber = "Input Flight Number: ";

        std::cout << kInputDestination;
        in >> flight.destination_;

        std::cout << kInputNumber;
        CheckNum(in, flight.flight_number_);

        in >> flight.airplane_ >> flight.date_ >> flight.tickets_;
    }
    return in;
}

bool operator==(const Flight &lhs, const Flight &rhs) {
    return std::tie(lhs.flight_number_, lhs.destination_, lhs.airplane_, lhs.date_, lhs.tickets_)
    == std::tie(rhs.flight_number_, rhs.destination_, rhs.airplane_, rhs.date_, rhs.tickets_);
}

int Flight::getFlightNumber() const {
    return flight_number_;
}

const std::string &Flight::getDestination() const {
    return destination_;
}

const Airplane &Flight::getAirplane() const {
    return airplane_;
}

const Date &Flight::getDate() const {
    return date_;
}

const Tickets &Flight::getTickets() const {
    return tickets_;
}
