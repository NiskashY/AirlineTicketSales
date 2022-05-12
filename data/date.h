#pragma once

#include <string>
#include <fstream>
#include <tuple>
#include <iomanip>

#include "../check_num.h"
#include "../appearance/width.h"
#include "validation_data.h"

struct Date {
    std::string departure_date_;
    std::string departure_time_;
    std::string arrival_time_;
};

void ShowDate(const Date&); // отобразить информацию о дате

std::istream &operator>>(std::istream &in, Date &date);

std::ostream &operator<<(std::ostream &out, const Date &date);

bool operator==(const Date& lhs, const Date& rhs);

bool operator<(const Date &lhs, const Date &rhs);
