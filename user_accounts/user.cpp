#include "user.h"

#pragma region dataManipulation

void User::ViewFlights(std::vector<Flight>& flights) const{
    ShowFlights(flights);
}

void User::BuyTickets(std::vector<Flight>& flights) {
    Reader reader("flights_database.txt");

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

Parameter GetParameter() {
    const auto &kInput = "Input Parameter for your operation\n1 - By FullFlights\n"
                         "2 - By Airplanes\n3 - By Date\n4 - By Tickets\nYour choice: ";
    const auto &kErrorPosition = "Your parameter should be [1; 4]. ReEnter:";
    const std::vector<Parameter> parameter_vec = {Parameter::Flight, Parameter::Airplane, Parameter::Date,
                                                  Parameter::Tickets};
    std::cout << kInput;
    int position = 0;
    do {
        CheckNum(std::cin, position);
        if (position < 1 || position > 5) {
            std::cout << kErrorPosition;
        }
    } while (position < 1 || position > 5);
    return parameter_vec[position - 1];
}

std::vector<Flight> User::SearchFlights() {
    const std::string kFileName_ = "flights_database.txt";
    std::ifstream in(kFileName_, std::ios::in);
    std::vector<Flight> matching_flights;

    // Parameter - what information we want to find
    switch (GetParameter()) {
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

std::vector<Flight> User::SortFlights(std::vector<Flight>& data) {
    // Parameter - what information we want to find
    switch (GetParameter()) {
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
    }
    return data;
}

#pragma endregion

#pragma region SignInSignUp

bool isLoginExist(std::vector<User>& all_users, const std::string &login) {
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

int InputAccess(std::istream& in) {
    const auto& kInput = "Input access level(0, 1, 2): ";
    const auto& kError = "Error: access level - (0, 1, 2). ReEnter: ";
    int access = 0;
    std::cout << kInput;
    do {
        CheckNum(std::cin, access);
        if (access < 0 || access > 2) {
            std::cout << kError;
        }
    } while (access < 0 || access > 2);
    return access;
}

User CreateNewUser(std::vector<User>& all_users) {
    const auto &kLoginExist = "Login already exist!. ReEnter: ";
    bool isExist = true;
    std::string login;
    do {
        login = InputLogin(std::cin);
        isExist = isLoginExist(all_users, login);
        if (isExist) {
            std::cout << kLoginExist;
        }
    } while (isExist);

    std::string password = InputPassword(std::cin);
    const int &access = 0;
    return {login, GenerateHashPassword(password), access};
}

bool SignIn(std::vector<User>& accounts, User &user) {
    const auto &kAccountNotFound = "Account not found!";
    const auto& kAccessDenied = "Access denied!";
    const auto& kWrongPassword = "\nWrong Password!";
    std::string login = InputLogin(std::cin);

    auto it = std::find_if(accounts.begin(), accounts.end(), [login](User &user_tmp) {
        return user_tmp.getLogin() == login;
    });

    bool isSignIn = false;
    if (it == accounts.end()) {
        std::cout << kAccountNotFound << '\n';
    } else {
        std::string salt = (*it).getPassword().salt;
        // TODO: *****************
        std::string password;

        // This try - catch if user input ':quit' to cancel password Input
        try {
            password = InputPassword(std::cin);
        } catch(std::runtime_error& e) {
            return false;
        }

        if (GetHash(password, salt) == (*it).getPassword().salted_hash_password) {
            user = (*it);
            if (user.getAccess() == 0) {
                std::cout << kAccessDenied << '\n';
            } else {
                isSignIn = true;
            }
        } else {
            std::cout << kWrongPassword << '\n';
        }
    }

    return isSignIn;
}

void SignUp(std::vector<User>& accounts) {
    const auto& kSuccess = "Account successfully added!";
    User new_user;
    std::string password;

    // This try - catch if user input ':quit' to cancel password Input
    try {
        new_user = CreateNewUser(accounts);
    } catch(std::runtime_error& e) {
        return;
    }

    Reader reader(ALL_USER_ACCOUNTS);
    reader.AddObject(new_user);
    std::cout << kSuccess << '\n';
}

#pragma endregion

#pragma region gettersAndSetters

const std::string &User::getLogin() const { return login_; }

const Password &User::getPassword() const { return password_; }

int User::getAccess() const { return access_; }

void User::setLogin(const std::string &login) { login_ = login; }

void User::setPassword(const Password &password) { password_ = password; }

void User::setAccess(int access) { access_ = access; }

#pragma endregion

std::istream &operator>>(std::istream &in, User &user) {
    if (typeid(in) == typeid(std::ifstream)) {
        in >> user.login_ >> user.password_ >> user.access_;
    } else {
        user.login_ = InputLogin(in);
        user.password_ = GenerateHashPassword(InputPassword(in));
        user.access_ = InputAccess(in);
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const User &user) {
    out << user.login_ << ' ' << user.password_ << ' ' << user.access_;
    return out;
}
