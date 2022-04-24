#pragma once
#include "flight.h"

#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

// Файл flights_database.txt находится в папке cmake-build-debug

class Reader {
private:
    const std::string kFileName_ = "flights_database.txt";

public:
    Reader() = default;

    explicit Reader(const std::string& kFileName) : kFileName_(kFileName) {}

    void AddFlight(const Flight& flight);

    void AddSeveralFlights(int& amount);

    std::vector<Flight> ReadFromFile() const;

    void WriteIntoFile(const std::vector<Flight>& all_flights) const;

    void DeleteFlight(const int& number);

    void ShowFlights(const std::vector<Flight>& vec) const;

    void Edit();

    std::vector<Flight> Search(const Parameter& parameter);
};

void SearchPartFlight(std::istream& in, std::vector<Flight>& matching_flights);

void SearchFullFlight(std::istream& in, std::vector<Flight>& matching_flights);

void SearchAirplane(std::istream& in, std::vector<Flight>& matching_flights);

void SearchDate(std::istream& in, std::vector<Flight>& matching_flights);

void SearchTickets(std::istream& in, std::vector<Flight>& matching_flights);

template <class T>
bool Compare(const T& lhs, const T& rhs) {
    return lhs == rhs;
}
