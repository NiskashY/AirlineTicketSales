#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <tuple>
#include <iomanip>

#include "../check_num.h"
#include "../reader/reader.h"
#include "validation_data.h"
#include "../appearance/width.h"

struct Tickets {
    int capacity = 0; // this field for correct amount of available seats (copy of airplane capacity)
    int available_in_business_ = 0;
    int price_of_business_ = 0;
    int available_in_economy_ = 0;
    int price_of_economy_ = 0;
};

void ShowTickets(const Tickets&);

std::istream &operator>>(std::istream &in, Tickets &tickets);

std::ostream &operator<<(std::ostream &out, const Tickets &tickets);

bool operator==(const Tickets& lhs, const Tickets& rhs);

bool operator<(const Tickets& lhs, const Tickets& rhs);
