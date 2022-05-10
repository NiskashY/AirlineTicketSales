#include "menues.h"

void ShowStartMenu() {
    const auto &kSignIn = "1 - Sign In";
    const auto &kSignUp = "2 - Sign Up";
    const auto &kExit = "3 - exit";
    const auto& kChoice = "Your choice: ";
    std::cout << kSignIn << '\n'
              << kSignUp << '\n'
              << kExit   << '\n'
              << kChoice;
}

void ShowFlightsViewHeader() {
    const std::string &kPos = "Pos.";
    const std::string &kHeaderFlight = "Flight";
    const std::string &kHeaderDestination = "Destination";
    const std::string &kHeaderNumber = "Number";

    const std::string &kHeaderAirplane = "Airplane";
    const std::string &kHeaderType = "Type";
    const std::string &kHeaderCapacity = "Capacity";

    const std::string &kHeaderDate = "Date";
    const std::string &kHeaderTime = "Time";
    const std::string &kHeaderDeparture = "Departure";
    const std::string &kHeaderArrival = "Arrival";

    const std::string &kHeaderBusiness = "Business Tickets";
    const std::string &kHeaderEconomy = "Economy Tickets";
    const std::string &kHeaderSeats = "Seats";
    const std::string &kHeaderPrice = "Price";

    const std::string &kSeparator = "|";

    // Table line separator
    std::cout << std::fixed << std::setfill('-') << std::setw(width::kTable) << '-' << std::setfill(' ')
              << '\n';

    std::cout << std::fixed << std::right
              << std::setw(width::kPos) << kSeparator
              << width::CenterString(kHeaderFlight, width::kWordLength + width::kNumbLength + width::kDelim)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderAirplane, width::kWordLength + width::kNumbLength + width::kDelim)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderDate, width::kDateLength)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderTime, width::kTimeLength * 2 + width::kDelim)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderBusiness, width::kNumbLength * 2 + width::kDelim)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderEconomy, width::kNumbLength * 2 + width::kDelim)
              << std::setw(width::kDelim) << kSeparator;

    std::cout << '\n' << std::fixed << std::setfill('-') << std::setw(width::kTable) << '-' << std::setfill(' ')
              << '\n';

    std::cout << std::setw(width::kPos) << kPos + kSeparator
              << width::CenterString(kHeaderDestination, width::kWordLength)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderNumber, width::kNumbLength)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderType, width::kWordLength)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderCapacity, width::kNumbLength)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderDeparture, width::kDateLength)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderDeparture, width::kTimeLength)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderArrival, width::kTimeLength)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderSeats, width::kNumbLength)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderPrice, width::kNumbLength)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderSeats, width::kNumbLength)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderPrice, width::kNumbLength)
              << std::setw(width::kDelim) << kSeparator;

    std::cout << '\n' << std::fixed << std::setfill('-') << std::setw(width::kTable) << '-' << std::setfill(' ')
              << '\n';
}

void ShowFlightsSection() { // and user and admin section
    const auto& kSection = "--------Flights Section--------";
    const auto& kViewFlights = "1 - View";
    const auto& kBuyTickets = "2 - Buy Ticket";
    const auto& kSearchFlights = "3 - Search";
    const auto& kSortFlights = "4 - Sort";

    std::cout << Paint(YELLOW, kSection) << '\n'
              << kViewFlights << '\n'
              << kBuyTickets << '\n'
              << kSearchFlights << '\n'
              << kSortFlights << '\n';
}

void ShowAccountViewHeader() {
    const auto &kHeaderLogins = "Logins";
    const auto &kHeaderPasswords = "Hash Passwords";
    const auto &kHeaderAccess = "Access";
    const auto &kSeparator = "|";
    const std::string &kPos = "Pos.";

    std::cout << std::fixed << std::setfill('-') << std::setw(width::kTableAccounts) << '-' << std::setfill(' ')
              << '\n';

    std::cout << std::fixed << std::right
              << std::setw(width::kPos) << kPos + kSeparator
              << width::CenterString(kHeaderLogins, width::kLogins)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderPasswords, width::kHashPasswords)
              << std::setw(width::kDelim) << kSeparator
              << width::CenterString(kHeaderAccess, width::kAccess)
              << std::setw(width::kDelim) << kSeparator;

    std::cout << '\n' << std::fixed << std::setfill('-') << std::setw(width::kTableAccounts) << '-' << std::setfill(' ')
              << '\n';
}

void ShowAdminMainMenu() {
    const auto &kSection = "--------Admin Main Menu--------";
    const auto &kFlights = "1 - Flights Section";
    const auto &kAccount = "2 - Accounts Section";
    const auto &kExit = "else - exit";
    const auto &kChoice = "Your choice: ";
    std::cout << Paint(YELLOW, kSection) << '\n'
              << kFlights << '\n'
              << kAccount << '\n'
              << kExit << '\n'
              << kChoice;
}

void ShowAdminFLightsSection() {
    ShowFlightsSection();
    const auto &kDeleteFlights = "5 - Delete";
    const auto &kAddFlights = "6 - Add";
    const auto &kEditFlight = "7 - Edit";
    const auto &kBack = "else - Back";
    const auto &kChoice = "Your choice: ";
    std::cout << kDeleteFlights << '\n'
              << kAddFlights << '\n'
              << kEditFlight << '\n'
              << kBack << '\n'
              << kChoice;
}

void ShowAdminAccountsSection() {
    const auto& kSection = "--------Accounts Section--------";
    const auto &kViewAccounts = "1 - View";
    const auto &kAddAccount = "2 - Add";
    const auto &kEditAccount = "3 - Edit";
    const auto &kDeleteAccount = "4 - Delete";
    const auto &kSortAccounts = "5 - Sort";
    const auto &kBack = "else - Back";
    const auto &kChoice = "Your choice: ";

    std::cout << Paint(YELLOW, kSection) << '\n'
              << kViewAccounts << '\n'
              << kAddAccount << '\n'
              << kEditAccount << '\n'
              << kDeleteAccount << '\n'
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
