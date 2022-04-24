/*
 *
 * TODO сделать проверки на ввод некорректных данных
 *
 */

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <tuple>
#include "../check_num.h"

struct Tickets {
    int available_in_business_ = 0;
    int price_of_business_ = 0;
    int available_in_economy_ = 0;
    int price_of_economy_ = 0;
};

std::istream &operator>>(std::istream &in, Tickets &tickets);

bool operator==(const Tickets& lhs, const Tickets& rhs);