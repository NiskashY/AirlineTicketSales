#include "airplane.h"

const std::string &Airplane::getType() const {
    return type_;
}

int Airplane::getCapacity() const {
    return capacity_;
}

std::istream &operator>>(std::istream &in, Airplane &airplane) {
    std::cout << "Input airplane type: ";
    CheckNum(in, airplane.type_);
    std::cout << "Input airplane capacity: ";
    CheckNum(in, airplane.capacity_);
    return in;
}

void Airplane::setType(const std::string &type) {
    type_ = type;
}

void Airplane::setCapacity(int capacity) {
    capacity_ = capacity;
}
