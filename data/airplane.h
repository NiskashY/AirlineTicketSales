#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <tuple>
#include <iomanip>

#include "../check_num.h"
#include "validation_data.h"
#include "../appearance/width.h"

struct Airplane {
    std::string type_;
    int capacity_ = 0;
};

void ShowAirplane(const Airplane&);

std::istream& operator>> (std::istream& in, Airplane& airplane);

std::ostream& operator<<(std::ostream &out, const Airplane& airplane);

bool operator==(const Airplane& lhs, const Airplane& rhs);

bool operator<(const Airplane& lhs, const Airplane& rhs);
