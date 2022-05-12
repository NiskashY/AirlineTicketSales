#pragma once
#include "user.h"
#include "../appearance/menues.h"

#pragma region accounts

void AddUser(std::vector<User>&, const User &); // добавить пользователя

void ShowUser(const User& user); // отобразить информацию о пользователе

void ViewUsers(const std::vector<User>& accounts); // отобразить всех пользователей

std::vector<User> SortAccounts(std::vector<User> users, const int& parameter); // сортировка аккаунтов

int SearchAccount(const std::vector<User>& users, const std::string& login); // поиск аккаунтов

void DeleteAccount(const User&, std::vector<User>&, const std::string&); // удаление аккаунтов

void EditAccount(User& user, int& position, std::vector<User>& users); // редактирование аккаунтов

void IncreaseAccessLevel(User& user); // увеличить уровень доступа
void DecreaseAccessLevel(User& user); // уменьшить уровень доступа
void BlockAccount(User& user); // блокировка аккаунта

#pragma endregion

#pragma region flights

void DeleteFlights(std::vector<Flight>&); // удаление рейса

void EditFlights(std::vector<Flight>&); // редактирование рейса

void AddFlights(std::vector<Flight>& ); // добавление рейса

#pragma endregion
