/*
 *
 * TODO: сделать проверки на ввод некорректных данных
 *
 */
#pragma once
#include <string>
#include <fstream>
#include <tuple>
#include "../check_num.h"

struct Date {
    std::string departure_date_;
    std::string departure_time_;
    std::string arrival_time_;
};

std::istream &operator>>(std::istream &in, Date &date);

bool operator==(const Date& lhs, const Date& rhs);
