#pragma once

#include <iostream>

#include "data/flight.h"
#include "data/ticket_purchase.h"
#include "reader/reader.h"
#include "user_accounts/user.h"
#include "user_accounts/admin_functional.h"
#include "appearance/menues.h"


bool isNeedToExit();

void Core(std::vector<User>&, std::vector<Flight>&);

void AdminFlightSection(User&, std::vector<Flight>&);

// when we do not provide tmp value from other function (for example main menu)
void DefaultUserFlightSection(std::vector<Flight>& flights, User& user, int tmp = -1);

void AdminAccountSection(User&, std::vector<User>&, std::vector<Flight>&);
