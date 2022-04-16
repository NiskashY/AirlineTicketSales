#pragma once
#include <iostream>

template <typename T>
std::istream& CheckNum(std::istream& in, T& var) {
    while (!(in >> var) || in.get() != '\n') {
        std::cout << "Error! Something go wrong ReEnter: ";
        in.clear();
        while (in.get() != '\n');
    }
    return in;
}