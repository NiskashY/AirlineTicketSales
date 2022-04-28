#pragma once
#include <string>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <fstream>

#include "sha256.h"

struct Password {
    std::string salted_hash_password;
    std::string salt;
};

bool operator==(std::string& pass, const Password& hash_password);

Password GenerateHashPassword(const std::string& pass);

std::string GenerateSalt();

std::string GetHash(const std::string& pass, const std::string& salt);

bool CheckPassword(const std::string& password);

std::string InputPassword(std::istream& in);

std::ostream &operator<<(std::ostream &out, const Password& password);

std::istream &operator>>(std::istream &in, Password &password);

bool operator==(const Password& lhs, const Password& rhs);