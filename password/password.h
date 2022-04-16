#pragma once
#include <string>
#include "sha256.h"
#include <iostream>
#include <chrono>

struct Password {
    std::string salted_hash_password;
    std::string salt;
};

bool operator==(std::string& pass, const Password& hash_password);

Password GenerateHashPassword(const std::string& pass);

std::string GenerateSalt();

std::string GetHash();
