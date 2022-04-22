#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include "flight.h"

// Файл flights_database.txt находится в папке cmake-build-debug

void AddFlight(const Flight& flight);

void AddSeveralFlights(int& amount);

std::vector<Flight> ReadFromFile(const std::string& kFileName = "flights_database.txt");
