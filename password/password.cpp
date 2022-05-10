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
    const std::string kBannedSymbols = "/\\?*-+'\"!;()%#$@^ ";
    return kBannedSymbols.find(symbol) == std::string::npos;
}

bool CheckPassword(const std::string &password) {
    return std::all_of(password.begin(), password.end(), isBanned) && password.length() >= 8;
}

std::string InputStarPassword() { // Password: ****** in console
    std::string password;
    while (true) {
        char c = getch();
        if (c == 13) // Enter
        {
            if (password.length() != 0)
                break;
        } else if (c == 8) // Backspace
        {
            if (password.length() != 0) {
                std::cout << "\b \b";
                password.pop_back();
            }
        } else if (c != 32) {
            password += c;
            std::cout << '*';
        }
    }
    std::cout << '\n';
    return password;
}

std::string InputPassword(std::istream& in, const std::string& mode) {
    const auto& kErrorMessage = "The password cannot contain /\\?*-+'\"!;()%#$@^ and spaces"
                                "\nAnd should be more than 8 characters. ReEnter.";
    std::string password;
    bool isPasswordCorrect = false;
    int incorrect_passwords = 0; // check if users input incorrect pass, and if so clear ErrorMessage

    do {
        std::cout << mode;
        password = InputStarPassword();
        if (password == ":quit") {
            ClearOutputAfterIncorrectPass(incorrect_passwords);
            throw std::runtime_error(":quit");
        }
        isPasswordCorrect = CheckPassword(password);
        if (!isPasswordCorrect) {
            std::cout << Paint(RED, kErrorMessage);
            GO_UP_LINE();
            GO_UP_LINE();
            CLEAR_LINE();
            GO_TO_COLUMN(0);
            incorrect_passwords++;
        }
    } while (!isPasswordCorrect);

    ClearOutputAfterIncorrectPass(incorrect_passwords);

    return password;
}


void ClearOutputAfterIncorrectPass(int& incorrect_passwords) {
    if (incorrect_passwords) {
        GO_DOWN_LINE();
        CLEAR_LINE();
        GO_UP_LINE();
        CLEAR_LINE();
    }
}

std::ostream &operator<<(std::ostream &out, const Password &password) {
    out << password.salted_hash_password;

    if (typeid(out) == typeid(std::ofstream)) {
        out << ' ' << password.salt;
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

