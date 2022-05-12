#pragma once

#include <iostream>

#include "../password/password.h"
#include "../data/flight.h"
#include "../data/ticket_purchase.h"
#include "../appearance/menues.h"
#include "../appearance/colors.h"


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
    void ViewFlights(const std::vector<Flight>&) const;

    void BuyTickets(std::vector<Flight>&);

    std::vector<Flight> SearchFlights(); // Search in File without reading data into vector

    std::vector<Flight> SortFlights(std::vector<Flight>); // Return Sorted vector of flights

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

bool isLoginUnique(std::vector<User>&, const std::string &); // является ли логин уникальным

std::string InputLogin(std::istream &in); // ввод логина

User CreateNewUser(std::vector<User>&); // создание нового пользователя

bool SignIn(std::vector<User>&, User &); // вход

void SignUp(std::vector<User>&); // регистрация

std::istream& operator>>(std::istream& in, User& user);

std::ostream& operator<<(std::ostream& out, const User& user);
