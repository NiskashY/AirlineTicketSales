/*
 *
 * TODO: сделать проверки на ввод некорректных данных
 *
 */
#pragma once

#include <iomanip>
#include <vector>
#include "airplane.h"
#include "date.h"
#include "tickets.h"
#include "reader.h"


enum class Parameter {
    Flight,
    Airplane,
    Date,
    Tickets,
    FullFlight
};

class Flight {
private:
    int flight_number_ = 0;
    std::string destination_;
    Airplane airplane_;
    Date date_;
    Tickets tickets_;

public:
    Flight() = default;

    Flight(const int& number, const std::string& destination) : flight_number_(number), destination_(destination) {}

    Flight(const int &number, const std::string &destination, Airplane &airplane, Date &date,
           Tickets &tickets)
            : flight_number_(number), destination_(destination), airplane_(airplane), date_(date), tickets_(tickets) {}

    int getFlightNumber() const;

    const std::string &getDestination() const;

    const Airplane &getAirplane() const;

    const Date &getDate() const;

    const Tickets &getTickets() const;

    void setFlightNumber(int flightNumber);

    void setDestination(const std::string &destination);

    void setAirplane(const Airplane &airplane);

    void setDate(const Date &date);

    void setTickets(const Tickets &tickets);

    friend std::ostream &operator<<(std::ostream &file, const Flight &flight);

    friend std::istream &operator>>(std::istream &file, Flight &flight);

    friend bool operator==(const Flight &lhs, const Flight &rhs);

    friend bool operator<(const Flight &lhs, const Flight &rhs);

};

Flight CreateFlight();

void ShowFlights();

void ShowFlights(const std::vector<Flight>& vec);

std::vector<Flight> Search(const Parameter& parameter);

void SearchPartFlight(std::istream& in, std::vector<Flight>& matching_flights);

void SearchFullFlight(std::istream& in, std::vector<Flight>& matching_flights);

void SearchAirplane(std::istream& in, std::vector<Flight>& matching_flights);

void SearchDate(std::istream& in, std::vector<Flight>& matching_flights);

void SearchTickets(std::istream& in, std::vector<Flight>& matching_flights);

template <class T>
bool Compare(const T& lhs, const T& rhs) {
    return lhs == rhs;
}

void Sort(const Parameter& parameter);

std::ostream& operator<<(std::ostream& file, const Flight& flight);

std::istream& operator>>(std::istream& file, Flight& flight);

bool operator==(const Flight& lhs, const Flight& rhs);

bool operator<(const Flight& lhs, const Flight& rhs);

void BuyTicket() {
/*    TODO: VALIDATION
 *          + ADD NOT ONLY WANT TOO BOOK PROPOSE USER
 *              BUSINESS ?
 *              ECONOMY  ?
 *          + ADD AMOUNT OF TICKETS
 */

    const auto& kInput = "Input number of flight you want too book";

    Reader reader("flights_database.txt");
    std::vector<Flight> flights;
    reader.ReadFromFile(flights);

    std::cout << kInput << '\n';
    int number = 0;
    CheckNum(std::cin, number);
    Tickets tickets = flights[number].getTickets();
    if (tickets.available_in_business_ > 0 &&)

}