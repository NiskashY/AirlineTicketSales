#pragma once
#include "flight.h"
#include "../reader/reader.h"
#include "validation_data.h"

bool BookEconomy(Tickets& available, const int& amount);

bool BookBusiness(Tickets& available, const int& amount);

bool BookTicket(Tickets& available_tickets, bool& isBooked);
