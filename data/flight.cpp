#include "flight.h"

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
    const int kTimeLength = 8;
    const int kNumbLength = 7;
    const int kDateLength = 13;
    const int kWordLength = 15;

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

    in >> flight.destination_ >> flight.flight_number_
       >> flight.airplane_ >> flight.date_ >> flight.tickets_;

    return in;
}



