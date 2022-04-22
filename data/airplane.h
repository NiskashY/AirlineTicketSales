/*
 *
 * TODO: сделать проверки на ввод некорректных данных
 *
 */
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "../check_num.h"

struct Airplane {
    std::string type_;
    int capacity_ = 0;
};

std::istream& operator>> (std::istream& in, Airplane& airplane);
