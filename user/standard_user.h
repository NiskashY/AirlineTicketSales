#pragma once
#include <string>
#include "user.h"

class StandardUser : public User {
private:
    bool access_ = false;

public:
    StandardUser(const std::string& login, const Password& password, Role& role, bool& access)
        : User(login, password, role), access_(access) {}

    void View();

};
