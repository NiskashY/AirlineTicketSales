#pragma once
#include <string>

class Date {
private:
    std::string departure_date_;
    std::string arrival_time_;
    std::string time_;

public:
    Date() = default;

    Date(const std::string &departure_date, const std::string &arrival_time, const std::string &time)
            : departure_date_(departure_date), arrival_time_(arrival_time), time_(time) {}

    const std::string &getDepartureDate() const;

    const std::string &getArrivalTime() const;

    const std::string &getTime() const;
};
