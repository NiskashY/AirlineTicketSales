#pragma once
#include "user.h"

/* ---------- ACCOUNTS ---------- */
void AddUser(const User &user);

void IncreaseAccessLevel(User& user);

bool SignIn(User& user);

void SignUp();

void AddUser(const User& user);

void ShowUser(const User& user);

void ViewUsers(const std::vector<User>& accounts);

void ViewUsers();

void SortAccounts(std::vector<User>& users, const int& parameter);

int SearchAccount(const std::vector<User>& users, const std::string& login);

void DeleteAccount(std::vector<User>& users, const std::string& login);

/* ---------- FLIGHTS ---------- */

template <class T>
void DeleteInfo(Reader& reader, std::vector<T>& data) {
    const auto& kSuccess = "Done!";
    const auto& kInputPositions = "Input positions you want to delete:\n";
    const auto& kPos = "position #";

    reader.ReadFromFile(data);
    int number = InputNumberOfDeleted();
    std::vector<int> positions(number);

    std::cout << kInputPositions;
    for (auto& item : positions) {
        std::cout << kPos;
        int pos = 0;
        CheckNum(std::cin, pos);
        item = pos;
    }

    std::sort(positions.begin(),positions.end());
    reader.DeleteObject(positions, data);

    std::cout << '\t' << kSuccess << '\n';
}

void DeleteFlights();

void EditFlights();

void AddFlights();

