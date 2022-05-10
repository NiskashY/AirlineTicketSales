#pragma once
#include "user.h"
#include "../appearance/menues.h"

#pragma region accounts

void AddUser(std::vector<User>&, const User &);

void IncreaseAccessLevel(User& user);

void AddUser(const User& user);

void ShowUser(const User& user);

void ViewUsers(const std::vector<User>& accounts);

void ViewUsers();

std::vector<User> SortAccounts(std::vector<User> users, const int& parameter);

int SearchAccount(const std::vector<User>& users, const std::string& login);

void DeleteAccount(const User&, std::vector<User>&, const std::string&);

void EditAccount(int& position, std::vector<User>& users);

void IncreaseAccessLevel(const int &position, std::vector<User> &users);
void DecreaseAccessLevel(const int &position, std::vector<User> &users);
void BlockAccount(const int &position, std::vector<User> &users);

#pragma endregion

#pragma region flights

void DeleteFlights(std::vector<Flight>&);

void EditFlights(std::vector<Flight>&);

void AddFlights(std::vector<Flight>& );

#pragma endregion
