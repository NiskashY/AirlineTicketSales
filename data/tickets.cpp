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
