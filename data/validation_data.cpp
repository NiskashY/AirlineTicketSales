#include "validation_data.h"

#pragma region input

int InputEditedPosition() {
    const auto &kInputNumber = "Input position you want to edit: ";
    const auto &kInvalidAmount = "Position cant be less then 0. ReEnter: ";
    const int &kMinValue = 0;

    std::cout << kInputNumber;
    int amount = 0;
    do {
        CheckNum(std::cin,amount);
        if (amount < kMinValue) {
            std::cout << kInvalidAmount << '\n';
        }
    } while (amount < kMinValue);

    return amount;
}

int InputAmountOfFlights() {
    const auto& kInputNumber = "Input amount of flights you want to create: ";
    const auto& kInvalidAmount = "Amount cant be greater then 100 and less then 0. ReEnter: ";
    const int& kMinValue = 0;
    const int& kMaxValue = 100;

    std::cout << kInputNumber;
    int amount = 0;
    do {
        CheckNum(std::cin,amount);
        if (amount < kMinValue || amount > kMaxValue) {
            std::cout << kInvalidAmount << '\n';
        }
    } while (amount < kMinValue || amount > kMaxValue);

    return amount;
}

int InputAmountSeats() {
    const auto &kInputAmountTickets = "Input amount of seats you want too book: ";
    const auto &kErrorAmountOfTickets = "The number of seats must be greater than 0!\nReEnter: ";
    const auto &kMinAmount = 1;
    int amount_of_tickets = 0;

    std::cout << kInputAmountTickets;
    do {
        CheckNum(std::cin, amount_of_tickets);
        if (amount_of_tickets < kMinAmount) {
            std::cout << kErrorAmountOfTickets;
        }
    } while (amount_of_tickets < kMinAmount);

    return amount_of_tickets;
}

int InputNumberOfFlight(const size_t &total_flights) {
    int number = 0;
    const std::string &kInput = "Input number of flight you want too book: ";
    const auto &kInvalidNumber = "The Flight with this number does not exist!";
    const int  &kMinNumber = 1;
    int errors = 0;

    do {
        std::cout << kInput;
        CheckNum(std::cin, number);
        if (number < kMinNumber || number > total_flights) {
            std::cout << "<number #" << number << ">  - " << Paint(RED, kInvalidNumber);
            GO_UP_LINE();
            CLEAR_LINE();
            GO_TO_COLUMN(0);
            ++errors;
        }
    } while (number < kMinNumber || number > total_flights);

    if (errors) {
        CLEAR_LINE();
        GO_TO_COLUMN(0);
    }

    return number;
}

#pragma endregion

#pragma region FlightsValidation

int InputFlightNumber(std::istream &in) {
    int number = 0;
    const auto &kInputNumber = "Input Flight Number: ";
    const auto &kIncorrectNumber = "FLight number should be [1; 10'000]. ReEnter: ";
    const int &kMaxNumber = 10'000;
    const int &kMinNumber = 1;
    std::cout << kInputNumber;

    do {
        CheckNum(in, number);
        if (number < kMinNumber || number > kMaxNumber) {
            std::cout << kIncorrectNumber;
        }
    } while (number < kMinNumber || number > kMaxNumber);

    return number;
}

std::string InputFlightDestination(std::istream &in) {
    const auto &kInputDestination = "Input Flight Destination: ";
    const auto &kErrorMessage = "Word is too long(length > 16) or has spaces. ReEnter: ";
    const int &kMaxLength = 16;
    std::string destination;

    std::cout << kInputDestination;
    bool isError = false;
    do {
        getline(in, destination);
        isError = destination.length() > kMaxLength || destination.find(' ') != std::string::npos;
        if (isError) {
            std::cout << Paint(RED, kErrorMessage);
        }
    } while (isError);

    return destination;
}

std::string InputAirplaneType(std::istream &in) {
    const auto &kInputDestination = "Input Airplane type: ";
    const auto &kErrorMessage = "Word is too long(length > 16) or has spaces. ReEnter: ";
    const int &kMaxLength = 16;
    std::string type;

    std::cout << kInputDestination;
    bool isError = false;
    do {
        getline(in, type);
        isError = type.length() > kMaxLength || type.find(' ') != std::string::npos;
        if (isError) {
            std::cout << Paint(RED, kErrorMessage);
        }
    } while (isError);

    return type;
}

int InputAirplaneCapacity(std::istream &in) {
    int capacity = 0;
    const auto &kInputCapacity = "Input Airplane capacity: ";
    const auto &kIncorrectNumber = "Airplane capacity should be [1; 853]. ReEnter: ";
    const int &kMaxCapacity = 853;
    const int &kMinCapacity = 1;
    std::cout << kInputCapacity;

    do {
        CheckNum(in, capacity);
        if (capacity < kMinCapacity || capacity > kMaxCapacity) {
            std::cout << kIncorrectNumber;
        }
    } while (capacity < kMinCapacity || capacity > kMaxCapacity);

    return capacity;
}

#pragma endregion

#pragma region TicketsValidation

int InputSeatsAmount(std::istream &in, const std::string &class_type, const int &kSeatsAvailable) {
    int seats_amount = 0;
    const auto &kInputCapacity = "Input available seats in " + class_type + ": ";
    const auto &kIncorrectNumber = "Available seats should be [0;" + std::to_string(kSeatsAvailable) + "]. ReEnter: ";
    const int &kMinSeatsAmount = 0;
    std::cout << kInputCapacity;

    do {
        CheckNum(in, seats_amount);
        if (seats_amount < kMinSeatsAmount || seats_amount > kSeatsAvailable) {
            std::cout << kIncorrectNumber;
        }
    } while (seats_amount < kMinSeatsAmount || seats_amount > kSeatsAvailable);

    return seats_amount;
}

int InputPrice(std::istream &in, const std::string &class_type) {
    int price = 0;
    const auto &kInputPrice = "Input ticket price for " + class_type + ": ";
    std::cout << kInputPrice;
    CheckNum(in, price);
    return price;
}

#pragma endregion

#pragma region DateValidation

void EnsureSymbol(std::stringstream &stream) {
    char symbol;
    stream >> symbol;
    if (symbol != '-') {
        throw std::runtime_error("Wrong date! Allowed Format - XX-MM-YYYY.");
    }
}

void isDayCorrect(int &day) {
    if  (day < 1 || day > 31) {
        throw std::runtime_error("The day is incorrect! (day - [1; 31].");
    }
}

void isMonthCorrect(int &month) {
    if (month < 1 || month > 12) {
        throw std::runtime_error("The month is incorrect! (month - [1; 12].");
    }
}

void isYearCorrect(int &year) {
    int current_year = (int)(time(nullptr) / 3.154e7 + 1970);
    if ( year < current_year|| year > current_year + 2) {
        throw std::runtime_error("The year is incorrect! (allowed from " + std::to_string(current_year) + " year.");
    }
}


// Calls the date, which may contain values of type -2-, to -02-
std::string SetFormattedDate(const int& day, const int& month, const int& year) {
    char zero = '0';
    char separator = '-';
    std::string str_day = std::to_string(day);
    if (day / 10 == 0) {
        str_day = zero + str_day;
    }
    std::string str_month= std::to_string(month);
    if (month / 10 == 0) {
        str_month = zero + str_month;
    }
    std::string str_year = std::to_string(year);

    return str_year + separator + str_month + separator + str_day;
}

bool ParseDate(std::string &date) {
    std::stringstream stream(date);
    const auto& kWrongFormat = "Wrong date! Allowed Format - XX-MM-YYYY.";
    int day = 0;
    int month = 0;
    int year = 0;

    if (stream.peek() < '0' || stream.peek() > '9' ) { // if first symbol of the stream not number;
        throw std::runtime_error(kWrongFormat);
    }

    stream >> day;
    isDayCorrect(day);
    EnsureSymbol(stream);
    stream >> month;
    isMonthCorrect(month);
    EnsureSymbol(stream);
    stream >> year;
    isYearCorrect(year);

    std::string tmp; // variable for read from stream. true if the stream has no errors(~ not empty), false otherwise(~ empty).
    if (stream >> tmp) {
        throw std::runtime_error(kWrongFormat);
    }

    date = SetFormattedDate(day, month, year); // set old day in correct format
    return true;  // if we counted everything from the stream, and it is empty
}

std::string InputDate(std::istream &in) {
    const auto& kInputDate = "Input flight departure date | XX-MM-YYYY |: ";
    std::cout << kInputDate;

    std::string date_tmp;
    bool isDateFormatOK = false;

    do {
        getline(in, date_tmp);
        try {
            isDateFormatOK = ParseDate(date_tmp);
        } catch (std::runtime_error& e) {
            std::cout << e.what() << "ReEnter: ";
        }
    } while (!isDateFormatOK);

    return date_tmp;
}

#pragma endregion

#pragma region TimeValidation

void isHoursCorrect(int &day) {
    if  (day < 0 || day > 24) {
        throw std::runtime_error("The hours is incorrect! (hours - [00; 24].");
    }
}

void isMinutesCorrect(int &month) {
    if (month < 0 || month > 59) {
        throw std::runtime_error("The minutes is incorrect! (minutes - [00; 59].");
    }
}

std::string SetFormattedTime(const int& hours, const int& minutes) {
    char zero = '0';
    char separator = '-';

    std::string str_hours= std::to_string(hours);
    if (hours / 10 == 0) {
        str_hours = zero + str_hours; // 1- => 01-
    }

    std::string str_minutes = std::to_string(minutes);
    if (minutes / 10 == 0) {
        str_minutes = zero + str_minutes; // -1- => -01-
    }

    return str_hours + separator + str_minutes;
}

bool ParseTime(std::string &time) {
    const auto& kWrongFormat = "Wrong time! Allowed Format - HH-MM.";
    std::stringstream stream(time);
    int hours = 0;
    int minutes = 0;

    if (stream.peek() < '0' || stream.peek() > '9' ) { // if first symbol of the stream not number;
        throw std::runtime_error(kWrongFormat);
    }

    stream >> hours;
    isHoursCorrect(hours);
    EnsureSymbol(stream);
    stream >> minutes;
    isMinutesCorrect(minutes);

    std::string tmp; // variable for read from stream. true if the stream has no errors(~ not empty), false otherwise(~ empty).
    if (stream >> tmp) {
        throw std::runtime_error(kWrongFormat);
    }

    time = SetFormattedTime(hours, minutes);

    return true;  // if we counted everything from the stream, and it is empty
}

std::string InputTime(std::istream &in, const std::string& type_of_date) {
    const auto& kInputDate = "Input flight " + type_of_date + " | HH-MM (24 clock)|: ";
    std::cout << kInputDate;

    std::string time_tmp;
    bool isTimeFormatOK = false;

    do {
        getline(in, time_tmp);
        try {
            isTimeFormatOK = ParseTime(time_tmp);
        } catch (std::runtime_error& e) {
            std::cout << e.what() << "ReEnter: ";
        }
    } while (!isTimeFormatOK);

    return time_tmp;
}

#pragma endregion
