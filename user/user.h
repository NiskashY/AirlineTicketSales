#pragma once

#include <string>
#include <fstream>
#include <memory>

#include "../password/password.h"
#include "../data/flight.h"
#include "../data/ticket_purchase.h"

enum class Role {
    User, Admin
};

class User {
private:
    std::string login_;
    Password password_;
    Role role_ = Role::User; // just initialisation

public:
    User() = default;

    // комментарий в следующей строке, чтобы не предлагало заменить на move(который при передаче в функцию работает
    // медленнее, чем &)
    User(const std::string& login, const Password& password, const Role& role) // NOLINT(modernize-pass-by-value)
        : login_(login), password_(password), role_(role) {}

    void ViewFlights() const;

    void BuyTickets();

    std::vector<Flight> SearchFlights(const Parameter& parameter);

    void SortFlights(const Parameter& parameter);

};
