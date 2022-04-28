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
    const auto& kSymbolsForSalt = "aA0bB1cC2dD3eE4fF5gG6hH7iI8jJ9kKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    const int kSaltSize = 16;
    const int kSymbolsSize = 62;

    srand(time(nullptr));
    std::string salt;
    salt.reserve(kSaltSize);

    for (int i = 0; i < kSaltSize; i++) {
        salt += kSymbolsForSalt[rand() % kSymbolsSize];
    }

    return salt;
}

bool isBanned(const char& symbol) {
    const std::string kBannedSymbols = "/\\?*-+'\"!;()%#$@^";
    return kBannedSymbols.find(symbol) == std::string::npos;
}

bool CheckPassword(const std::string &password) {
    return std::all_of(password.begin(), password.end(), isBanned);
}

std::string InputPassword(std::istream& in) {
    // TODO: сделать ***** - это уже реализовать на WINDOWS
    const auto& kInputPassword = "Input password: ";
    const auto& kErrorMessage = "The password cannot contain /\\?*-+'\"!;()%#$@^. ReEnter:";
    std::string password;
    bool isPasswordCorrect = false;

    std::cout << kInputPassword;
    do {
        getline(in, password);
        isPasswordCorrect = CheckPassword(password);
        if (!isPasswordCorrect) {
            std::cout << kErrorMessage;
        }
    } while (!isPasswordCorrect);

    return password;
}

Password SignUpInputPassword(std::istream &in) {
    auto password = InputPassword(in);
    return GenerateHashPassword(password);
}

std::ostream &operator<<(std::ostream &out, const Password &password) {
    out << password.salted_hash_password << ' ';

    if (typeid(out) == typeid(std::ofstream)) {
        out << password.salt;
    }

    return out;
}

std::istream &operator>>(std::istream &in, Password &password) {
    in >> password.salted_hash_password;
    in >> password.salt;
    return in;
}

bool operator==(const Password &lhs, const Password &rhs) {
    return std::tie(lhs.salted_hash_password, lhs.salt)
           == std::tie(rhs.salted_hash_password, rhs.salt);
}

