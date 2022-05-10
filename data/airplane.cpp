#include "airplane.h"

void ShowAirplane(const Airplane& airplane) {
    const auto& kDelim = "|";

    std::cout << std::setw(width::kWordLength) << airplane.type_
            << std::setw(width::kDelim) << kDelim
            << std::setw(width::kNumbLength) << airplane.capacity_
            << std::setw(width::kDelim) << kDelim;
}

std::istream &operator>>(std::istream &in, Airplane &airplane) {
    if (typeid(in) == typeid(std::ifstream)) {
        in >> airplane.type_ >> airplane.capacity_;
    }
    else {
        airplane.type_ = InputAirplaneType(in);
        airplane.capacity_ = InputAirplaneCapacity(in);
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Airplane &airplane) {
    out << airplane.type_ << ' ' << airplane.capacity_;
    return out;
}

bool operator==(const Airplane& lhs, const Airplane& rhs) {
    return (lhs.type_ == rhs.type_ || lhs.capacity_ ==  rhs.capacity_);
}

bool operator<(const Airplane& lhs, const Airplane& rhs) {
    return std::tie(lhs.type_, lhs.capacity_) < std::tie(rhs.type_, rhs.capacity_);
}
