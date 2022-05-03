#include "admin_functional.h"

#pragma region accounts

void AddUser(std::vector<User>& accounts, const User &user) {
    Reader reader(ALL_USER_ACCOUNTS);
    reader.AddObject(user);
    accounts.push_back(user);
}

void ShowUser(const User &user) {
    const auto &kAdmin = "Admin";
    const auto &kApprovedUser = "User";
    const auto &kNotApproved = "awaits confirmation";
    const auto &kSeparator = "|";
    int access_tmp = user.getAccess();

    std::cout << std::fixed
              << std::setw(width::kLogins) << user.getLogin()
              << std::setw(width::kDelim) << kSeparator
              << std::setw(width::kHashPasswords) << user.getPassword()
              << std::setw(width::kDelim) << kSeparator;

    if (access_tmp == 0) {
        std::cout << std::setw(width::kAccess) << kNotApproved;
    } else if (access_tmp == 1) {
        std::cout << std::setw(width::kAccess) << kApprovedUser;
    } else {
        std::cout << std::setw(width::kAccess) << kAdmin;
    }

    std::cout << std::setw(width::kDelim) << kSeparator;
    std::cout << '\n';
}

void ViewUsers(const std::vector<User>& accounts) {
    ShowAccountViewHeader();
    int position = 0;
    for (auto& item : accounts) {
        position++;
        std::cout << std::right <<'#' << std::setw(3) << std::setfill('0') << position << std::setfill(' ')
                  << std::left << " | ";
        ShowUser(item);
    }
}

bool ascendingLogin(const User& lhs, const User& rhs) {
    return lhs.getLogin() < rhs.getLogin();
}

bool descendingLogin(const User& lhs, const User& rhs) {
    return lhs.getLogin() > rhs.getLogin();
}

bool ascendingAccess(const User& lhs, const User& rhs) {
    return lhs.getAccess() < rhs.getAccess();
}

bool descendingAccess(const User& lhs, const User& rhs) {
    return lhs.getAccess() > rhs.getAccess();
}

void SortAccounts(std::vector<User>& users, const int& parameter) {
    bool (*predicate)(const User&, const User&); // pointer to the function from above
    switch(parameter) {
        case 1: {
            predicate = ascendingLogin;
            break;
        }
        case 2: {
            predicate = ascendingAccess;
            break;
        }
        case 3: {
            predicate = descendingLogin;
            break;
        }
        case 4: {
            predicate = descendingAccess;
            break;
        }
        default: {
            return;
        }
    }
    std::sort(users.begin(), users.end(), predicate);
}

int SearchAccount(const std::vector<User>& users, const std::string& login) {
    const auto& kNotMatch = "Account doesn't exist!";
    auto it = std::find_if(users.begin(), users.end(), [login](const User& user) {
        return user.getLogin() == login;
    });
    if (it == users.end()) {
        std::cout << kNotMatch << '\n';
        return -1; // user with this login doesn't exist
    } else {
        return int(it - users.begin());
    }
}

void DeleteAccount(std::vector<User>& users, const std::string& login) {
    int position = SearchAccount(users, login);
    Reader reader(ALL_USER_ACCOUNTS);
    reader.DeleteObject({position}, users);
}

void EditAccount(int& position, std::vector<User>& users) {
    User old_user;
    --position;
    try {
        old_user = users.at(position);
    } catch( std::out_of_range& e) {
        const auto& kInvalidNumber = "The Information with this number does not exist";
        std::cout << Paint(RED, kInvalidNumber) << '\n';
        return;
    }

    const auto& kEditMenu = "1 - Login\n2 - Password\n3 - Access\nelse - back\nYour choice: ";
    Reader reader(ALL_USER_ACCOUNTS);

    std::cout << kEditMenu;
    int choice = 0;
    CheckNum(std::cin, choice);
    switch(choice) {
        case 1: {
            std::string new_login = InputLogin(std::cin);
            old_user.setLogin(new_login);
            break;
        }
        case 2: {
            Password new_password = GenerateHashPassword(InputPassword(std::cin, "Input new Password "));
            old_user.setPassword(new_password);
            break;
        }
        case 3: {
            const auto& kAccessMenu = "\nCurrent access - " + std::to_string(users[position].getAccess())
                    + "\n1 - Increase access level\n2 - Decrease access level\n3 - Block User\nelse - back\nYour Choice: ";
            std::cout << kAccessMenu;
            int tmp = 0;
            CheckNum(std::cin, tmp);
            if (tmp == 1) {
                IncreaseAccessLevel(position, users);
            } else if (tmp == 2) {
                DecreaseAccessLevel(position, users);
            } else if (tmp == 3) {
                BlockAccount(position, users);
            } else {
                return;
            }

        }
        default: {
            return;
        }
    }
    reader.WriteIntoFile(users);
    std::cout << Paint(GREEN, "\tDone!") << '\n';
}

void IncreaseAccessLevel(const int &position, std::vector<User> &users) {
    int access_before = users[position].getAccess();
    if (access_before != 2) {
        users[position].setAccess(++access_before);
    }
}

void DecreaseAccessLevel(const int &position, std::vector<User> &users) {
    int access_before = users[position].getAccess() ;
    if (access_before != 0) {
        users[position].setAccess(--access_before);
    }
}

void BlockAccount(const int &position, std::vector<User> &users) {
    int blocked_access = 0;
    users[position].setAccess(blocked_access);
}



#pragma endregion

#pragma region flights

void DeleteFlights(std::vector<Flight>& flights) {
    const auto& kSuccess = "Done!";
    const auto& kInputPositions = "Input positions you want to delete:\n";
    const auto& kPos = "position #";
    Reader reader(FLIGHTS_DATABASE);

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
    reader.DeleteObject(positions, flights);

    std::cout << '\t' << kSuccess << '\n';
}

void EditFlights(std::vector<Flight>& flights) {
    Reader reader(FLIGHTS_DATABASE);
    const auto& kNewInfo = "NEW INFORMATION: ";
    int position = InputEditedPosition();
    Flight old_flight;

    --position;
    try {
        old_flight = flights.at(position);
    } catch( std::out_of_range& e) {
        const auto& kInvalidNumber = "The Information with this number does not exist";
        std::cout << Paint(RED, kInvalidNumber) << '\n';
        return;
    }

    std::cout << '\n' << Paint(YELLOW, kNewInfo) << '\n';
    switch (GetParameter()) {
        case Parameter::Flight : {
            std::cin >> old_flight; // set new info
            break;
        }
        case Parameter::Airplane : {
            Airplane new_Airplane;
            std::cin >> new_Airplane;
            old_flight.setAirplane(new_Airplane);

            // this if for correct work of free places in plane
            Tickets tmp = old_flight.getTickets();
            tmp.capacity = new_Airplane.capacity_;
            old_flight.setTickets(tmp);
            break;
        }
        case Parameter::Date: {
            Date new_date;
            std::cin >> new_date;
            old_flight.setDate(new_date);
            break;
        }
        case Parameter::Tickets: {
            Tickets new_tickets;
            new_tickets.capacity = old_flight.getAirplane().capacity_;
            std::cin >> new_tickets;
            old_flight.setTickets(new_tickets);
            break;
        }
    }
    flights[position] = old_flight;
    reader.WriteIntoFile(flights);
}

void AddFlights(std::vector<Flight>& all_flights) {
    const auto& kSuccess = "Successfully added!";
    Reader reader(FLIGHTS_DATABASE);

    auto flights_tmp = CreateFlights();
    reader.AddSeveralObjects(flights_tmp);
    all_flights.insert(all_flights.end(), flights_tmp.begin(), flights_tmp.end());
    std::cout << Paint(GREEN, kSuccess) << '\n';
}

#pragma endregion
