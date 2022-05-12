#pragma once

#include <iostream>
#include <iomanip>
#include "width.h"
#include "colors.h"

void ShowFlightsViewHeader(); // отображает заголовок таблицы рейсов

void ShowAccountViewHeader(); // отображает заголовок таблицы аккаунтов

void ShowStartMenu(); // отображает начальное меню

void ShowFlightsSection(); // отображает меню рейсов

void ShowAdminMainMenu(); // отображает меню админа

void ShowAdminFLightsSection(); // отображает меню рейсов с возможностями админа

void ShowAdminAccountsSection(); // отображает меню аккаунтов

void ShowAccountMenuSort(); // отображает меню сортировки аккаунтов

void ShowAccessMenu(const std::string&); // отображает меню при изменении доступа пользователя
