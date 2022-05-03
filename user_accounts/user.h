#pragma once

#include <iostream>

#include "../password/password.h"
#include "../data/flight.h"
#include "../data/ticket_purchase.h"
#include "../appearance/menues.h"
#include "../appearance/colors.h"

#define ALL_USER_ACCOUNTS "user_accounts.txt"
#define FLIGHTS_DATABASE "flights_database.txt"

// Manipulation of cursor in console

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
    void ViewFlights(std::vector<Flight>&) const;

    void BuyTickets(std::vector<Flight>&);

    std::vector<Flight> SearchFlights();

    std::vector<Flight> SortFlights(std::vector<Flight>&);

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

bool isLoginExist(std::vector<User>&, const std::string &);

std::string InputLogin(std::istream &in);

User CreateNewUser(std::vector<User>&);

bool SignIn(std::vector<User>&, User &);

void SignUp(std::vector<User>&);

std::istream& operator>>(std::istream& in, User& user);

std::ostream& operator<<(std::ostream& out, const User& user);
