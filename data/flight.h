#pragma once

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

};

