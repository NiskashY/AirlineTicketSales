#pragma once

#include <iostream>
#include <iomanip>
#include "width.h"
#include "colors.h"

void ShowFlightsViewHeader();

void ShowAccountViewHeader();

void ShowFlightViewSection();

void ShowStartMenu();

void ShowFlightsSection();

void ShowAdminMainMenu();

// TODO: СДЕЛАТЬ ВЫБОР КАКОЕ ПОЛЕ Я ХОЧУ ОТРЕДАКТИРОВАТЬ
void ShowAdminFLightsSection();

void ShowAdminAccountsSection();

void ShowAccountMenuSort();

void PasswordMenu();

void ShowAccessMenu(const std::string&);
