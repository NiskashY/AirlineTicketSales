/*
 *
 * TODO: сделать проверки на ввод некорректных данных
 *
 */
#pragma once

#include <iomanip>
#include "airplane.h"
#include "date.h"
#include "tickets.h"

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

    friend std::ostream &operator<<(std::ostream &file, const Flight &flight);

    friend std::istream &operator>>(std::istream &file, Flight &flight);

    friend bool operator==(const Flight &lhs, const Flight &rhs);

};

std::ostream& operator<<(std::ostream& file, const Flight& flight);

std::istream& operator>>(std::istream& file, Flight& flight);

bool operator==(const Flight& lhs, const Flight& rhs);

Flight CreateFlight();
