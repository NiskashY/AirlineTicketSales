#include "tickets.h"

int Tickets::getAvailableInBusiness() const {
    return available_in_business_;
}

int Tickets::getPriceOfBusiness() const {
    return price_of_business_;
}

int Tickets::getAvailableInEconomy() const {
    return available_in_economy_;
}

int Tickets::getPriceOfEconomy() const {
    return price_of_economy_;
}

void Tickets::setAvailableInBusiness(int availableInBusiness) {
    available_in_business_ = availableInBusiness;
}

void Tickets::setPriceOfBusiness(int priceOfBusiness) {
    price_of_business_ = priceOfBusiness;
}

void Tickets::setAvailableInEconomy(int availableInEconomy) {
    available_in_economy_ = availableInEconomy;
}

void Tickets::setPriceOfEconomy(int priceOfEconomy) {
    price_of_economy_ = priceOfEconomy;
}


std::istream &operator>>(std::istream &in, Tickets &tickets) {
    std::cout << "Input available seats in business class: ";
    CheckNum(in, tickets.available_in_business_);
    std::cout << "Input price of business class: ";
    CheckNum(in, tickets.price_of_business_);
    std::cout << "Input available seats in economy class: ";
    CheckNum(in, tickets.available_in_economy_);
    std::cout << "Input price of economy class: ";
    CheckNum(in, tickets.price_of_economy_);
    return in;
}
