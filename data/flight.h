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

class Flight : public Airplane, public Date, public Tickets {
private:
    std::string flight_number_;
    std::string destination_;

public:
    Flight() = default;

    Flight(const std::string &number, const std::string &destination, Airplane &airplane, Date &date, Tickets &tickets)
            : flight_number_(number), destination_(destination), Airplane(airplane), Date(date), Tickets(tickets) {}

    const std::string &getFlightNumber() const;

    const std::string &getDestination() const;

    void setFlightNumber(const std::string &flightNumber);

    void setDestination(const std::string &destination);

    friend std::ostream &operator<<(std::ostream &file, const Flight &flight);

    friend std::istream &operator>>(std::istream &file, Flight &flight);

    void ShowFlight() const;
};

std::ostream& operator<<(std::ostream& file, const Flight& flight);

std::istream& operator>>(std::istream& file, Flight& flight);

Flight CreateFlight();
