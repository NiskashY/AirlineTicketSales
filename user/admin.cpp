#include "admin.h"

void Admin::AddFlights() {
    const auto& kSuccess = "Successfully added!";
    Reader reader("flights_database.txt");

    auto flights = CreateFlights();
    reader.AddSeveralObjects(flights);

    std::cout << kSuccess << '\n';
}

void Admin::DeleteFlights() {
    Reader reader("flights_database.txt");
    std::vector<Flight> flights;
    DeleteInfo(reader, flights);
}

