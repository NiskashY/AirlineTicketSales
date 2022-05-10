#pragma once

#include <sstream>
#include <ctime>

#include "../appearance/colors.h"
#include "../check_num.h"

int InputEditedPosition();

int InputAmountOfFlights();

int InputNumberOfDeleted();

int InputAmountSeats();

// Number of Flight - number of flight in file 1, 2, ..., n
int InputNumberOfFlight(const size_t &total_flights);

/*-------------- AIRPLANE VALIDATION ----------*/

int InputFlightNumber(std::istream& in);

std::string InputFlightDestination(std::istream& in);

std::string InputAirplaneType(std::istream &in);

int InputAirplaneCapacity(std::istream &in);

/*-------------- TICKETS VALIDATION ----------*/

int InputSeatsAmount(std::istream &, const std::string&, const int&);

int InputPrice(std::istream &in, const std::string &class_type);

/*-------------- DATE VALIDATION ----------*/

void EnsureSymbol(std::stringstream& stream);

void isDayCorrect(int&);

void isMonthCorrect(int&);

void isYearCorrect(int& );

std::string SetFormattedDate(const int&, const int&, const int&);

bool ParseDate(std::string& date);

std::string InputDate(std::istream &in);

/*-------------- TIME VALIDATION ----------*/

void isHoursCorrect(int &);

void isMinutesCorrect(int &);

bool ParseTime(std::string &);

std::string SetFormattedTime(const int&, const int&);

std::string InputTime(std::istream &in, const std::string& type_of_date);

