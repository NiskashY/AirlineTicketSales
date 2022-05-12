#include "admin_functional.h"

#pragma region accounts

void AddUser(std::vector<User>& accounts, const User &user) {
    Reader reader(ALL_USER_ACCOUNTS);
    reader.AddObject(user);
    accounts.push_back(user);
}

void ShowUser(const User &user) {
    const std::string &kMain = "Main";
    std::string kAdmin = "Admin";
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
        std::cout << BLUE << std::setw(width::kAccess)
                  << kNotApproved; // если управляющие символы ansi после setw - ломается вывод
    } else if (access_tmp == 1) {
        std::cout << GREEN << std::setw(width::kAccess) << kApprovedUser;
    } else {
        if (access_tmp == 3) {
            kAdmin = kMain + " " + kAdmin;
        }
        std::cout << RED << std::setw(width::kAccess) << kAdmin;
    }

    std::cout << RESET_COLOR;

    std::cout << std::setw(width::kDelim) << kSeparator;
    std::cout << '\n';
}

void ViewUsers(const std::vector<User>& accounts) {
    ShowAccountViewHeader();
    int position = 0;
    for (auto& item : accounts) {
        position++;

        if (position % 2) {
            std::cout << BACK_GREY;
        }

        std::cout << std::right <<'#' << std::setw(3) << std::setfill('0') << position << std::setfill(' ')
                  << std::left << " | ";

        ShowUser(item);
        std::cout << RESET_COLOR;
    }
    std::cout << std::fixed << std::setfill('-') << std::setw(width::kTableAccounts) << '-' << std::setfill(' ')
              << '\n';
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

std::vector<User> SortAccounts(std::vector<User> users, const int& parameter) {
    bool (*predicate)(const User&, const User&); // pointer to the function from above
    switch(parameter) {
        case 1: default: {
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
    }
    std::sort(users.begin(), users.end(), predicate);
    return users;
}

int SearchAccount(const std::vector<User>& users, const std::string& login) {
    const auto& kNotMatch = "Account doesn't exist!";
    auto it = std::find_if(users.begin(), users.end(), [login](const User& user) {
        return user.getLogin() == login;
    });
    if (it == users.end()) {
        std::cout << '\n' << Paint(RED, kNotMatch) << '\n';
        return -1; // user with this login doesn't exist
    } else {
        return int(it - users.begin() + 1);
    }
}

void DeleteAccount(const User& user, std::vector<User>& users, const std::string& login) {
    int position = SearchAccount(users, login);

    if (position > -1) { // if account exist.
        if (users[position].getAccess() > user.getAccess()) { // if user = Admin and he tries to delete Main Admin
            const std::string &kError = "You cant delete Main Admin... hahahaha";
            std::cout << '\n' << Paint(RED, kError) << '\n';
        } else {
            Reader reader(ALL_USER_ACCOUNTS);
            reader.DeleteObject({position}, users);
        }
    }
}

void EditAccount(User& user,int& position, std::vector<User>& users) {
    User old_user;
    --position;
    try {
        old_user = users.at(position);
    } catch( std::out_of_range& e) {
        const auto& kInvalidNumber = "The Information with this number does not exist";
        std::cout << Paint(RED, kInvalidNumber) << '\n';
        return;
    }

    if (old_user.getAccess() == 3 && user.getAccess() != 3) {
        const auto& kMainAdmin = "You cant edit main admin)";
        std::cout << Paint(YELLOW, kMainAdmin) << '\n';
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
            ShowAccessMenu(std::to_string(old_user.getAccess()));
            int tmp = 0;
            CheckNum(std::cin, tmp);
            if (tmp == 1) {
                IncreaseAccessLevel(old_user);
            } else if (tmp == 2) {
                DecreaseAccessLevel(old_user);
            } else if (tmp == 3) {
                BlockAccount(old_user);
            } else {
                return;
            }
            break;
        }
        default: {
            return;
        }
    }
    users[position] = old_user;
    reader.WriteIntoFile(users);
    std::cout << Paint(GREEN, "\tDone!") << '\n';
}

void IncreaseAccessLevel(User& user) {
    int access_before = user.getAccess();
    if (access_before < 2) {
        user.setAccess(++access_before);
    }
}

void DecreaseAccessLevel(User& user)  {
    int access_before = user.getAccess() ;
    if (access_before > 0) {
        user.setAccess(--access_before);
    }
}

void BlockAccount(User& user)  {
    int blocked_access = 0;
    user.setAccess(blocked_access);
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
    const auto& kSuccess = "Information successfully edited!";
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

    std::cout << '\n' << Paint(GREEN, kSuccess) << '\n';
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
