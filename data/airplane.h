/*
 *
 * TODO: сделать проверки на ввод некорректных данных
 *
 */
#pragma once
#include <string>
#include <iostream>
#include "../check_num.h"

class Airplane {
protected:
    std::string type_;
    int capacity_ = 0;

public:
    Airplane() = default;

    Airplane(const std::string &type, const int &capacity)
            : type_(type), capacity_(capacity) {}

    const std::string &getType() const;

    int getCapacity() const;

    void setType(const std::string &type);

    void setCapacity(int capacity);

    friend std::istream& operator>> (std::istream& in, Airplane& airplane);

};

std::istream& operator>> (std::istream& in, Airplane& airplane);

