#include "admin_functional.h"

void AddUser(const User &user) {
    Reader reader(ALL_USER_ACCOUNTS);
    reader.AddObject(user);
}

void IncreaseAccessLevel(User &user) {
    auto tmp = user.getAccess();
    user.setAccess(++tmp);
}

void ShowHeader() {
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

void ShowUser(const User &user) {
    const int &kLoginWidth = 20;
    const auto& kAdmin = "Admin";
    const auto& kApprovedUser = "confirmed User";
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

void ViewUsers() {
    Reader reader(ALL_USER_ACCOUNTS);
    std::vector<User> accounts;
    reader.ReadFromFile(accounts);

    ShowHeader();
    int position = 0;
    for (auto& item : accounts) {
        position++;
        std::cout << '#' << position << ' ';
        ShowUser(item);
    }
}

void ViewUsers(const std::vector<User>& accounts) {
    ShowHeader();
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
        case 1 : default: {
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

/* ---------- FLIGHTS ---------- */

void DeleteFlights() {
    Reader reader(FLIGHTS_DATABASE);
    std::vector<Flight> flights;
    DeleteInfo(reader, flights);
}

void EditFlights() {
    Reader reader(FLIGHTS_DATABASE);
    std::vector<Flight> flights;
    reader.ReadFromFile(flights);
    int position = InputEditedPosition();
    reader.Edit(position, flights);
}

void AddFlights() {
    const auto& kSuccess = "Successfully added!";
    Reader reader(FLIGHTS_DATABASE);

    auto flights = CreateFlights();
    reader.AddSeveralObjects(flights);

    std::cout << kSuccess << '\n';
}

