#include "airplane.h"

std::istream &operator>>(std::istream &in, Airplane &airplane) {
    // TODO: ADD VALIDATION!!!
    if (typeid(in) == typeid(std::ifstream)) {
        in >> airplane.type_ >> airplane.capacity_;
    }
    else {
        std::cout << "Input airplane type: ";
        in >> airplane.type_;
        std::cout << "Input airplane capacity: ";
        CheckNum(in, airplane.capacity_);
    }
    return in;
}

bool operator==(const Airplane& lhs, const Airplane& rhs) {
    return std::tie(lhs.type_, lhs.capacity_) == std::tie(rhs.type_, rhs.capacity_);
}
