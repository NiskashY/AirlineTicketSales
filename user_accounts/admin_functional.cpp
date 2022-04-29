#include "admin_functional.h"

#pragma region accounts

void AddUser(std::vector<User>& accounts, const User &user) {
    Reader reader(ALL_USER_ACCOUNTS);
    reader.AddObject(user);
    accounts.push_back(user);
}

void ShowUser(const User &user) {
    const int &kLoginWidth = 20;
    const auto& kAdmin = "Admin";
    const auto& kApprovedUser = "User";
    const auto& kNotApproved = "awaits confirmation";
    int access_tmp = user.getAccess();

    std::cout << std::fixed
              << std::setw(kLoginWidth) << user.getLogin() << " | "
              << user.getPassword() << " | ";

    if (access_tmp == 0) {
        std::cout << kNotApproved;
    } else if (access_tmp == 1) {
        std::cout << kApprovedUser;
    } else {
        std::cout << kAdmin;
    }
    std::cout << '\n';
}

void ViewUsers(const std::vector<User>& accounts) {
    ShowAccountViewHeader();
    int position = 0;
    for (auto& item : accounts) {
        position++;
        std::cout << '#' << position << ' ';
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

void EditAccount(const int& position, std::vector<User>& users) {
    Reader reader(ALL_USER_ACCOUNTS);
    reader.Edit(position - 1, users);
}


void ConfirmAccount(const int& position, std::vector<User>& users) {
//    const auto& kInputPos = "Input account position you want "
    Reader reader(ALL_USER_ACCOUNTS);
    int access_before = users[position].getAccess() ;
    users[position].setAccess(++access_before);
    reader.WriteIntoFile(users);
}

void BlockAccount(const int& position, std::vector<User>& users) {
//    const auto& kInputPos = "Input account position you want "
    Reader reader(ALL_USER_ACCOUNTS);
    int block_access = 0;
    users[position].setAccess(block_access);
    reader.WriteIntoFile(users);
}

void IncreaseAccessLevel(User &user) {
    auto tmp = user.getAccess();
    user.setAccess(++tmp);
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
    int position = InputEditedPosition();
    reader.Edit(position, flights);
}

void AddFlights(std::vector<Flight>& all_flights) {
    const auto& kSuccess = "Successfully added!";
    Reader reader(FLIGHTS_DATABASE);

    auto flights_tmp = CreateFlights();
    reader.AddSeveralObjects(flights_tmp);
    all_flights.insert(all_flights.end(), flights_tmp.begin(), flights_tmp.end());
    std::cout << kSuccess << '\n';
}

#pragma endregion
