#include "menues.h"
void ShowAccountViewHeader() {
    const auto &kHeaderLogins = "Logins";
    const auto &kHeaderPasswords = "Hash Passwords";
    const auto &kHeaderAccess = "Access";
    const int &kLoginsPos = 14;
    const int &kHashPasswordsPos =
            20 - kLoginsPos + 64 / 2 + 7 + 3; // 64 - length of hashPass, 20 length of Login, 7 - kHeader / 2, 3 - ' | '
    const int &kAccessPos = 64 + 3 - kHashPasswordsPos + kLoginsPos + 11;


    std::cout << std::fixed
              << std::setw(kLoginsPos) << kHeaderLogins
              << std::setw(kHashPasswordsPos) << kHeaderPasswords
              << std::setw(kAccessPos) << kHeaderAccess << '\n';
}

void ShowStartMenu() {
    const auto &kSignIn = "1 - Sign in";
    const auto &kSignUp = "2 - Sign Up";
    const auto &kExit = "3 - exit";
    const auto& kChoice = "Your choice: ";
    std::cout << kSignIn << '\n'
              << kSignUp << '\n'
              << kExit   << '\n'
              << kChoice;
}

void ShowFlightsSection() { // and user and admin section
    const auto& kViewFlights = "1 - View all available flights";
    const auto& kBuyTickets = "2 - Buy Ticket";
    const auto& kSearchFlights = "3 - Search Flights";
    const auto& kSortFlights = "4 - Sort Flights";
    std::cout << kViewFlights << '\n'
              << kBuyTickets << '\n'
              << kSearchFlights << '\n'
              << kSortFlights << '\n';
}

void ShowAdminMainMenu() {
    const auto &kFlights = "1 - Flights section";
    const auto &kAccount = "2 - Accounts section";
    const auto &kExit = "else - exit";
    const auto &kChoice = "Your choice: ";
    std::cout << kFlights << '\n'
              << kAccount << '\n'
              << kExit << '\n'
              << kChoice;
}

void ShowAdminFLightsSection() {
    ShowFlightsSection();
    const auto &kDeleteFlights = "5 - Delete flights";
    const auto &kAddFlights = "6 - Add Flights";
    const auto &kEditFlight = "7 - Edit flight section";
    const auto &kBack = "else - Back";
    const auto &kChoice = "Your choice: ";
    std::cout << kDeleteFlights << '\n'
              << kAddFlights << '\n'
              << kEditFlight << '\n'
              << kBack << '\n'
              << kChoice;
}

void ShowAdminAccountsSection() {
    const auto &kDeleteAccount = "1 - Delete account";
    const auto &kAddAccount = "2 - Add account";
    const auto &kEditAccount = "3 - Edit account section";
    const auto &kViewAccounts = "4 - View accounts";
    const auto &kSortAccounts = "5 - Sort accounts";
    const auto &kBack = "else - Back";
    const auto &kChoice = "Your choice: ";
    std::cout << kDeleteAccount << '\n'
              << kAddAccount << '\n'
              << kEditAccount << '\n'
              << kViewAccounts << '\n'
              << kSortAccounts << '\n'
              << kBack << '\n'
              << kChoice;
}

void ShowAccountMenuSort() {
    const auto& kInput = "Input how you want to sort:";
    const auto& kAscendingLogin = "1 - Ascending Login";
    const auto& kAscendingAccess = "2 - Ascending Access";
    const auto& kDescendingLogin = "3 - Descending Login";
    const auto& kDescendingAccess = "4 - Descending Access";
    const auto& kBack = "else - Back\nYour choice: ";
    std::cout << kInput << '\n';
    std::cout << kAscendingLogin << '\n';
    std::cout << kAscendingAccess << '\n';
    std::cout << kDescendingLogin << '\n';
    std::cout << kDescendingAccess << '\n';
    std::cout << kBack;
}