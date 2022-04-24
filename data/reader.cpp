#include "reader.h"

void Reader::ShowFlights(const std::vector<Flight>& vec) const {
    const std::string kVecEmpty = "Nothing to show :(";
    int position = 0;
    if (vec.empty()) {
        std::cout << "\t" << kVecEmpty << "\n";
    }
    for (auto &flight: vec) {
        ++position;
        std::cout << '#' << position << ' ' << std::left << flight << '\n';
    }
}

void Reader::AddFlight(const Flight &flight) {
    std::ofstream file(kFileName_, std::ios::app);
    file << '\n' << flight;
    file.close();
}

void Reader::AddSeveralFlights(int &amount) {
    const std::string kSuggest = "Input information about flight: ";
    for (int i = 1; i <= amount; ++i) {
        std::cout << "#" << i << ' ' << kSuggest << '\n';
        AddFlight(CreateFlight());
        std::cout << '\n';
    }
}

std::vector<Flight> Reader::ReadFromFile() const {
    std::ifstream in (kFileName_, std::ios::in);
    std::vector<Flight> all_available_flights;

    while(!in.eof()) {
        Flight tmp;
        in >> tmp;
        all_available_flights.push_back(tmp);
    }

    in.close();
    return all_available_flights;
}

void Reader::WriteIntoFile(const std::vector<Flight>& all_flights) const {
    std::ofstream out(kFileName_, std::ios::out);
    for (auto& flight : all_flights) {
        out << '\n' << flight;
    }
    out.close();
}

void Reader::DeleteFlight(const int &number) {
    const std::string kSuccessDelete = "Flight successfully deleted!";
    const std::string kInvalidNumber = "The flight with this number does not exist";

    auto all_flights = ReadFromFile();
    auto it = all_flights.begin() + number - 1;
    if (it < all_flights.end() && it >= all_flights.begin()) {
        all_flights.erase(it);
        WriteIntoFile(all_flights);
        std::cout << kSuccessDelete << '\n';
    } else {
        std::cout << kInvalidNumber << '\n';
    }
}

std::vector<Flight> Reader::Search(const Parameter& parameter) {
    std::ifstream in(kFileName_, std::ios::in);
    std::vector<Flight> matching_flights;

    // Parameter - what information we want to find
    switch (parameter) {
        case Parameter::Flight : {
            SearchPartFlight(in, matching_flights);
            break;
        }
        case Parameter::Airplane : {
            SearchAirplane(in, matching_flights);
            break;
        }
        case Parameter::Date: {
            SearchDate(in, matching_flights);
            break;
        }
        case Parameter::Tickets: {
            SearchTickets(in, matching_flights);
            break;
        }
        default : {
            SearchFullFlight(in, matching_flights);
        }
    }

    in.close();
    return matching_flights;
}

void SearchPartFlight(std::istream& in, std::vector<Flight>& matching_flights) {
    const std::string kInputDestination = "Input Flight Destination: ";
    const std::string kInputNumber = "Input Flight Number: ";

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
    const std::string kWarning = "WARNING: You sure you want to search full information about flights ? 1 - y, else - n";

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
