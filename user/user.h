/**
 *
 * TODO: Реализовать методы Search и Sort для User.
 *
 */

#pragma once
#include <string>

enum class Role {
    User, Admin
};

struct Password {
    std::string salted_hash_password;
    std::string salt;
};

class User {
private:
    const std::string kLogin;
    const Password kPassword;
    Role role_;

public:
    User(const std::string& login, const Password& password, Role role)
        : kLogin(login), kPassword(password), role_(role) {}

//    Search();
//
//    Sort();
//
//    Request();

    virtual void View() = 0;

};