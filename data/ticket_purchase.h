#pragma once
#include "flight.h"
#include "../reader/reader.h"
#include "validation_data.h"

bool BookEconomy(Tickets& available, const int& amount); // Заказать билет в эконом классе

bool BookBusiness(Tickets& available, const int& amount); // заказать билет в бизнес-классе

bool BookTicket(Tickets& available_tickets, bool& isBooked); // заказать билет
