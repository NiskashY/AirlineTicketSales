/*
 *
 * TODO: сделать проверки на ввод некорректных данных
 *
 */
#pragma once
#include <string>
#include "../check_num.h"

class Date {
protected:
    std::string departure_date_;
    std::string departure_time_;
    std::string arrival_time_;

public:
    Date() = default;

    Date(const std::string &departure_date, const std::string &arrival_time, const std::string &time)
            : departure_date_(departure_date), arrival_time_(arrival_time), departure_time_(time) {}

    const std::string &getDepartureDate() const;

    const std::string &getArrivalTime() const;

    const std::string &getTime() const;

    void setDepartureDate(const std::string &departureDate);

    void setDepartureTime(const std::string &departureTime);

    void setArrivalTime(const std::string &arrivalTime);

    friend std::istream &operator>>(std::istream &in, Date &date);
};


std::istream &operator>>(std::istream &in, Date &date);

