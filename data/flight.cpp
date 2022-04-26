#include "flight.h"

std::vector<Flight> CreateFlights() {
    int n = InputAmountOfFlights();
    std::vector<Flight> flights(n);
    for (auto& item : flights) {
        std::cin >> item;
    }
    return flights;
}

void ShowFlights(const std::vector<Flight> &vec) {
    int position = 0;

    for (auto &flight: vec) {
        ++position;
        std::cout << '#' << position << ' ' << std::left << flight << '\n';
    }
}

void ShowFlights() {
    int position = 0;

    std::vector<Flight> vec;
    Reader reader("flights_database.txt");
    reader.ReadFromFile(vec);

    for (auto &flight: vec) {
        ++position;
        std::cout << '#' << std::setw(3) << std::left << position << ' ' << flight << '\n';
    }
}

/*   -------------SEARCH SECTION------------- */

void SearchPartFlight(std::istream& in, std::vector<Flight>& matching_flights) {
    const auto& kInputDestination = "Input Flight Destination: ";
    const auto& kInputNumber = "Input Flight Number: ";

    int flight_number;
    std::string destination;

    std::cout << kInputDestination;
    std::cin >> destination;
    std::cout << kInputNumber;
    CheckNum(std::cin, flight_number);

    while (!in.eof()) {
        Flight tmp;
        in >> tmp;

        if (Compare(std::make_tuple(tmp.getFlightNumber(), tmp.getDestination()) , std::make_tuple(flight_number, destination))) {
            matching_flights.push_back(tmp);
        }
    }
}

void SearchFullFlight(std::istream& in, std::vector<Flight>& matching_flights) {
    const auto& kWarning = "WARNING: You sure you want to search full information about flights ? 1 - y, else - n";

    std::cout << kWarning << '\t';
    std::string choice;
    std::cin >> choice;

    if (choice == "1") {
        Flight flight;
        std::cin >> flight;
        while (!in.eof()) {
            Flight tmp;
            in >> tmp;
            if (Compare(tmp, flight)) {
                matching_flights.push_back(tmp);
            }
        }
    }
}

void SearchAirplane(std::istream& in, std::vector<Flight>& matching_flights) {
    Airplane airplane;
    std::cin >> airplane;

    while (!in.eof()) {
        Flight tmp;
        in >> tmp;
        if (Compare(tmp.getAirplane(), airplane)){
            matching_flights.push_back(tmp);
        }
    }
}

void SearchDate(std::istream& in, std::vector<Flight>& matching_flights) {
    Date date;
    std::cin >> date;

    while (!in.eof()) {
        Flight tmp;
        in >> tmp;
        if (Compare(tmp.getDate(), date)) {
            matching_flights.push_back(tmp);
        }
    }
}

void SearchTickets(std::istream& in, std::vector<Flight>& matching_flights) {
    Tickets tickets;
    std::cin >> tickets;

    while (!in.eof()) {
        Flight tmp;
        in >> tmp;
        if (Compare(tmp.getTickets(), tickets)) {
            matching_flights.push_back(tmp);
        }
    }
}

/* ---------------- GETTERS and SETTERS ---------------- */

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

void Flight::setFlightNumber(int flightNumber) {
    flight_number_ = flightNumber;
}

void Flight::setDestination(const std::string &destination) {
    destination_ = destination;
}

void Flight::setAirplane(const Airplane &airplane) {
    airplane_ = airplane;
}

void Flight::setDate(const Date &date) {
    date_ = date;
}

void Flight::setTickets(const Tickets &tickets) {
    tickets_ = tickets;
}

/* ------------ OVERLOAD OPERATORS ------- */

std::ostream &operator<<(std::ostream &out, const Flight &flight) {
    const int kNumbLength = 7;
    const int kWordLength = 16;

    out << std::fixed
        << std::setw(kWordLength) << flight.destination_
        << std::setw(kNumbLength) << flight.flight_number_
        << flight.airplane_
        << flight.date_
        << flight.tickets_;

    return out;
}

std::istream &operator>>(std::istream &in, Flight &flight) {
    if (typeid(in) == typeid(std::ifstream)) {
        in >> flight.destination_ >> flight.flight_number_
           >> flight.airplane_ >> flight.date_ >> flight.tickets_;
    } else {
        flight.destination_ = InputFlightDestination(in);
        flight.flight_number_ = InputFlightNumber(in);

        in >> flight.airplane_ >> flight.date_;
        flight.tickets_.capacity = flight.airplane_.capacity_; // this is for correct amount of seats in tickets.
        in >> flight.tickets_;

    }
    return in;
}

bool operator==(const Flight &lhs, const Flight &rhs) {
    return std::tie(lhs.flight_number_, lhs.destination_, lhs.airplane_, lhs.date_, lhs.tickets_)
           == std::tie(rhs.flight_number_, rhs.destination_, rhs.airplane_, rhs.date_, rhs.tickets_);
}

bool operator<(const Flight &lhs, const Flight &rhs) {
    return std::tie(lhs.flight_number_, lhs.destination_, lhs.airplane_, lhs.date_, lhs.tickets_)
           < std::tie(rhs.flight_number_, rhs.destination_, rhs.airplane_, rhs.date_, rhs.tickets_);
}
