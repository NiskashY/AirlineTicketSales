#pragma once

#include <sstream>

#include "../check_num.h"

int InputEditedPosition();

int InputAmountOfFlights();

int InputNumberOfDeleted();

int InputAmountTickets();

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

void isDayCorrect(int& day);

void isMonthCorrect(int& month);

void isYearCorrect(int& year);

bool ParseDate(const std::string& date);

std::string InputDate(std::istream &in);

/*-------------- TIME VALIDATION ----------*/

void isHoursCorrect(int &day);

void isMinutesCorrect(int &month);

bool ParseTime(const std::string &date);

std::string InputTime(std::istream &in, const std::string& type_of_date);

