#pragma once

#include <conio.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>

#include "sha256.h"
#include "../appearance/colors.h"

struct Password {
    std::string salted_hash_password;
    std::string salt;
};

bool operator==(std::string& pass, const Password& hash_password);

Password GenerateHashPassword(const std::string& pass); // генерация нового хэшированного пароля

std::string GenerateSalt(); // генерация соли

std::string GetHash(const std::string& pass, const std::string& salt); // получить хэшированный пароль из двух строк (соли и пароля-строки)

bool CheckPassword(const std::string& password); // проверить валидный ли пароль

std::string InputPassword(std::istream& in, const std::string& mode);

void ClearOutputAfterIncorrectPass(int&); // очистка консоли после неправильно введенного пароля

std::ostream &operator<<(std::ostream &out, const Password& password);

std::istream &operator>>(std::istream &in, Password &password);

bool operator==(const Password& lhs, const Password& rhs);