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

class Flight {
private:
    std::string flight_number_;
    std::string destination_;
    Airplane airplane_;
    Date date_;
    Tickets tickets_;

public:
    Flight() = default;

    Flight(const std::string &number, const std::string &destination, Airplane &airplane, Date &date, Tickets &tickets) // NOLINT(modernize-pass-by-value)
            : flight_number_(number), destination_(destination), airplane_(airplane), date_(date), tickets_(tickets) {}

    friend std::ostream &operator<<(std::ostream &file, const Flight &flight);

    friend std::istream &operator>>(std::istream &file, Flight &flight);

};

std::ostream& operator<<(std::ostream& file, const Flight& flight);

std::istream& operator>>(std::istream& file, Flight& flight);

Flight CreateFlight();
