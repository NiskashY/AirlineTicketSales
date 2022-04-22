#include "airplane.h"

std::istream &operator>>(std::istream &in, Airplane &airplane) {
    if (typeid(in) == typeid(std::ifstream)) {
        in >> airplane.type_ >> airplane.capacity_;
    }
    else {
        std::cout << "Input airplane type: ";
        CheckNum(in, airplane.type_);
        std::cout << "Input airplane capacity: ";
        CheckNum(in, airplane.capacity_);
    }
    return in;
}
