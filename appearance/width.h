#pragma once
#include <iostream>
#include <iomanip>

namespace width {
#pragma region flights

    const int kNumbLength = 10;
    const int kWordLength = 16;
    const int kTimeLength = 10;
    const int kDateLength = 14;
    const int kDelim = 2;
    const int kPos = 6;
    const int kTable = kTimeLength * 2 + kNumbLength * 6 + kWordLength * 2 + kDateLength + 11 * 2 + kPos; // 11 - amount of delims

#pragma endregion

#pragma region accounts

    const int kLogins= 20;
    const int kHashPasswords = 65;
    const int kAccess = 21;
    const int kTableAccounts = kLogins + kHashPasswords + kAccess + 3 * kDelim + kPos;

#pragma endregion

    std::string CenterString(const std::string& str, const int& width);
}

