#pragma once
#include <string>

class Tickets {
private:
    int available_in_business_ = 0;
    int price_of_business_ = 0;
    int available_in_economy_ = 0;
    int price_of_economy_ = 0;

public:

    Tickets() = default;

    Tickets(const int &seats_in_bs, const int &price_bs, const int &seats_in_ec, const int &price_ec)
            : available_in_business_(seats_in_bs), price_of_business_(price_bs),
              available_in_economy_(seats_in_ec), price_of_economy_(price_ec) {}

    int getAvailableInBusiness() const;

    int getPriceOfBusiness() const;

    int getAvailableInEconomy() const;

    int getPriceOfEconomy() const;
};