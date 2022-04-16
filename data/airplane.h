#pragma once
#include <string>

class Airplane {
private:
    std::string type_;
    int capacity = 0;

public:
    Airplane() = default;

    Airplane(const std::string &type, const int &capacity)
            : type_(type), capacity(capacity) {}

    const std::string &getType() const;

    int getCapacity() const;

};
