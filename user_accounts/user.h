#pragma once

#include <iostream>

#include "../password/password.h"
#include "../data/flight.h"
#include "../data/ticket_purchase.h"

#define ALL_USER_ACCOUNTS "user_accounts.txt"
#define FLIGHTS_DATABASE "flights_database.txt"

class User {
private:
    std::string login_;
    Password password_;
    int access_ = 0;

public:
    User() = default;

    User(const std::string &login, const Password &password, const int &access) : login_(login), password_(password),
                                                                                  access_(access) {}

    // Basic user functions
    void ViewFlights() const;

    void BuyTickets();

    std::vector<Flight> SearchFlights(const Parameter &parameter);

    void SortFlights(const Parameter &parameter);

    // ---Getters ad setters---
    int getAccess() const;

    const std::string &getLogin() const;

    const Password &getPassword() const;

    void setLogin(const std::string &login);

    void setAccess(int access);

    void setPassword(const Password &password);

    // --Overload >> <<
    friend std::istream &operator>>(std::istream &in, User &user);

    friend std::ostream &operator<<(std::ostream &out, const User &user);

};

bool isLoginExist(const std::string &login);

std::string InputLogin(std::istream &in);

bool SignIn(User& user);

void SignUp();

std::istream& operator>>(std::istream& in, User& user);

std::ostream& operator<<(std::ostream& out, const User& user);
