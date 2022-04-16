#include "password.h"

std::string GetHash(const std::string& pass, const std::string& salt) {
    return sha256(sha256(pass + salt) + sha256(pass));
}

bool operator==(std::string& pass, const Password& hash_password) {
    return GetHash(pass, hash_password.salt) == hash_password.salted_hash_password;
}

Password GenerateHashPassword(const std::string& pass) {
    std::string salt = GenerateSalt();
    return {GetHash(pass, salt), salt};
}

std::string GenerateSalt() {
    const std::string kSymbolsForSalt = "aA0bB1cC2dD3eE4fF5gG6hH7iI8jJ9kKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    const int kSaltSize = 16;
    const int kSymbolsSize = 62;

    srand(time(NULL));
    std::string salt;
    salt.reserve(kSaltSize);

    for (int i = 0; i < kSaltSize; i++) {
        salt.push_back(kSymbolsForSalt[rand() % kSymbolsSize]);
    }

    return salt;
}