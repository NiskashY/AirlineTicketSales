#include "user.h"

void User::ViewFlights() const{
    ShowFlights();
}

void User::BuyTickets() {
    Reader reader("flights_database.txt");
    std::vector<Flight> flights;
    reader.ReadFromFile(flights);

    const auto &kSuccessBooked = "The Ticket was successfully booked!";
    const auto &kNotEnoughSeats = "There are not enough seats on this flight!\n"
                                  "1 - Choose another flight\nelse - exit\t Your choice: ";

    while(true) {
        int number = InputNumberOfFlight(flights.size());
        Tickets available_tickets = flights[number - 1].getTickets();

        bool isBooked = false;

        // if I need to exit;
        if (BookTicket(available_tickets, isBooked)) {
            return;
        }

        if (isBooked) {
            std::cout << kSuccessBooked << '\n';
            flights[number - 1].setTickets(available_tickets);
            reader.WriteIntoFile(flights);
            break;
        } else {
            std::cout << kNotEnoughSeats;
            std::string request;
            std::cin >> request;
            if (request != "1") {
                return;
            }
        }
    }
}

std::vector<Flight> User::SearchFlights(const Parameter& parameter) {
    const std::string kFileName_ = "flights_database.txt";
    std::ifstream in(kFileName_, std::ios::in);
    std::vector<Flight> matching_flights;

    // Parameter - what information we want to find
    switch (parameter) {
        case Parameter::Flight : {
            SearchPartFlight(in, matching_flights);
            break;
        }
        case Parameter::Airplane : {
            SearchAirplane(in, matching_flights);
            break;
        }
        case Parameter::Date: {
            SearchDate(in, matching_flights);
            break;
        }
        case Parameter::Tickets: {
            SearchTickets(in, matching_flights);
            break;
        }
        default : {
            SearchFullFlight(in, matching_flights);
        }
    }

    in.close();
    return matching_flights;
}

void User::SortFlights(const Parameter &parameter) {
    Reader reader("flights_database.txt");
    std::vector<Flight> data;
    reader.ReadFromFile(data);

    // Parameter - what information we want to find
    switch (parameter) {
        case Parameter::Flight : {
            std::sort(data.begin(), data.end());
            break;
        }
        case Parameter::Airplane : {
            std::sort(data.begin(), data.end(), [](const Flight& lhs, const Flight& rhs) {
                return lhs.getAirplane() < rhs.getAirplane();
            });
            break;
        }
        case Parameter::Date: {
            std::sort(data.begin(), data.end(), [](const Flight& lhs, const Flight& rhs) {
                return lhs.getDate() < rhs.getDate();
            });
            break;
        }
        case Parameter::Tickets: {
            std::sort(data.begin(), data.end(), [](const Flight& lhs, const Flight& rhs) {
                return lhs.getTickets() < rhs.getTickets();
            });
            break;
        }
        default : {
            return;
        }
    }
    reader.WriteIntoFile(data);
}

/* ------- SIGN IN / SIGN UP -------- */
bool isLoginExist(const std::string &login) {
    Reader reader(ALL_USER_ACCOUNTS);
    std::vector<User> all_users;
    reader.ReadFromFile(all_users);
    if (std::find_if(all_users.begin(), all_users.end(), [login](const User& user) {
        return user.getLogin() == login;
    }) != all_users.end()) {
        return true;
    }
    return false;
}

std::string InputLogin(std::istream &in) {
    const auto &kInputLogin = "Input login: ";
    std::string login;
    std::cout << kInputLogin;
    getline(in, login);
    return login;
}

bool SignIn(User &user) {
    const auto &kAccountNotFound = "Account not found!";
    const auto& kAccessDenied = "Access denied!";
    std::string login = InputLogin(std::cin);

    Reader reader(ALL_USER_ACCOUNTS);
    std::vector<User> accounts;
    reader.ReadFromFile(accounts, false);

    auto it = std::find_if(accounts.begin(), accounts.end(), [login](User &user_tmp) {
        return user_tmp.getLogin() == login;
    });

    bool isSignIn = false;
    if (it == accounts.end()) {
        std::cout << kAccountNotFound << '\n';
    } else {
        std::string salt = (*it).getPassword().salt;
        // TODO: *****************
        std::string password = InputPassword(std::cin);

        if (GetHash(password, salt) == (*it).getPassword().salted_hash_password) {
            user = (*it);
            if (user.getAccess() == 0) {
                std::cout << kAccessDenied << '\n';
            } else {
                isSignIn = true;
            }
        }
    }

    return isSignIn;
}

void SignUp() {
    const auto& kLoginExist = "Login already exist!. ReEnter: ";
    const auto& kSuccess = "Account successfully added!";
    bool isExist = true;
    std::string login;
    do {
        login = InputLogin(std::cin);
        isExist = isLoginExist(login);
        if (isExist) {
            std::cout << kLoginExist;
        }
    } while (isExist);

    std::string password = InputPassword(std::cin);
    const int& access = 0;
    Reader reader(ALL_USER_ACCOUNTS);
    reader.AddObject(User(login, GenerateHashPassword(password), access));
    std::cout << kSuccess << '\n';
}

/* ---------------------- */
const std::string &User::getLogin() const { return login_; }

const Password &User::getPassword() const { return password_; }

int User::getAccess() const { return access_; }

void User::setLogin(const std::string &login) { login_ = login; }

void User::setPassword(const Password &password) { password_ = password; }

void User::setAccess(int access) { access_ = access; }

std::istream &operator>>(std::istream &in, User &user) {
    in >> user.login_ >> user.password_ >> user.access_;
    return in;
}

std::ostream &operator<<(std::ostream &out, const User &user) {
    out << user.login_ << ' ' << user.password_ << ' ' << user.access_;
    return out;
}
