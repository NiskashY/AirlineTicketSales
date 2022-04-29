#pragma once
#include "user.h"
#include "../menues.h"

#pragma region accounts

void AddUser(std::vector<User>&, const User &);

void IncreaseAccessLevel(User& user);

void AddUser(const User& user);

void ShowUser(const User& user);

void ViewUsers(const std::vector<User>& accounts);

void ViewUsers();

void SortAccounts(std::vector<User>& users, const int& parameter);

int SearchAccount(const std::vector<User>& users, const std::string& login);

void DeleteAccount(std::vector<User>& users, const std::string& login);

void EditAccount(const int& position, std::vector<User>& users);

void ConfirmAccount(const int& position);

#pragma endregion

#pragma region flights

void DeleteFlights(std::vector<Flight>&);

void EditFlights(std::vector<Flight>&);

void AddFlights(std::vector<Flight>& );

#pragma endregion
