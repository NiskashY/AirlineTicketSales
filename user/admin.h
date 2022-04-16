#pragma once
#include <string>
#include "user.h"

class Admin : public User {
public:
    Admin(const std::string& login, const Password& password, Role& role)
            : User(login, password, role) {}


//    Add() {
//
//    }
//
//    Edit() {
//
//    }
//
//    Delete() {
//
//    }
//

};