#include "user.h"

#pragma region dataManipulation

void User::ViewFlights(const std::vector<Flight>& flights) const{
    ShowFlightsViewHeader();
    ShowFlights(flights);
}

void User::BuyTickets(std::vector<Flight>& flights) {
    Reader reader("flights_database.txt");

    const auto &kSuccessBooked = "The Ticket was successfully booked!";
    const auto &kNotEnoughSeats = "There are not enough seats on this flight!\n"
                                  "1 - Choose another flight\nelse - exit\nYour choice: ";

    while(true) {
        int number = InputNumberOfFlight(flights.size());
        Tickets available_tickets = flights[number - 1].getTickets();

        bool isBooked = false;

        // if I need to exit;
        if (BookTicket(available_tickets, isBooked)) {
            return;
        }

        if (isBooked) {
            std::cout << Paint(GREEN, kSuccessBooked) << '\n';
            flights[number - 1].setTickets(available_tickets);
            reader.WriteIntoFile(flights);
            break;
        } else {
            CLEAR_LINES(12); // clear output console stream
            std::cout << '\n';

            std::cout << Paint(YELLOW, kNotEnoughSeats);
            std::string request;
            std::cin >> request;
            if (request != "1") {
                return;
            }

            CLEAR_LINES(5); // clear output console stream
            std::cout << '\n';
        }
    }
}

Parameter GetParameter() {
    const auto &kInput = "Input Parameter for your operation\n1 - Flights\n"
                         "2 - Airplanes\n3 - Date\n4 - Tickets\nYour choice: ";
    const auto &kErrorPosition = "Your parameter should be [1; 4]. ReEnter:";
    const std::vector<Parameter> parameter_vec = {Parameter::Flight, Parameter::Airplane, Parameter::Date,
                                                  Parameter::Tickets};
    std::cout << kInput;
    int position = 0;
    do {
        CheckNum(std::cin, position);
        if (position < 1 || position > 4) {
            std::cout << kErrorPosition;
        }
    } while (position < 1 || position > 4);
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

std::vector<Flight> User::SortFlights(std::vector<Flight> data) {
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
    const std::string &kInputLogin = "Input login: ";
    const auto &kError = "Login can't contain spaces and be empty";

    std::string login;
    int wrong_login = 0;
    bool isError = false;
    do {
        std::cout << kInputLogin;
        getline(in, login);
        isError = (login.empty() || login.find(' ') != std::string::npos);
        if (isError) {
            std::cout << Paint(RED, kError);
            wrong_login++;
            GO_UP_LINE();
            CLEAR_LINE();
            GO_TO_COLUMN(0);
        }
    } while (isError);

    if (wrong_login) {
        CLEAR_LINE();
    }

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
    const std::string& kInput = "Input ";
    const std::string& kConfirm = "Confirm ";
    const std::string& kPassword = "Password(':quit' - cancel): ";

    bool isExist = true;
    std::string login;
    do {
        login = InputLogin(std::cin);
        isExist = isLoginExist(all_users, login);
        if (isExist) {
            std::cout << kLoginExist;
        }
    } while (isExist);

    std::string password;
    std::string password_confirm;
    do {
        password = InputPassword(std::cin, kInput + kPassword);
        password_confirm = InputPassword(std::cin, kConfirm + kPassword);
        if (password != password_confirm) {
            std::cout << "Password not equal!\n";
        }
    } while (password != password_confirm);

    const int &access = 0;
    return {login, GenerateHashPassword(password), access};
}

bool SignIn(std::vector<User>& accounts, User &user) {
    const auto &kAccountNotFound = "Account not found!";
    const auto& kAccessDenied = "Access denied!";
    const auto& kWrongPassword = "\nWrong Password!";
    const std::string& kPassword = "Password(':quit' - cancel): ";
    const std::string& kInput = "Input ";

    std::string login = InputLogin(std::cin);

    auto it = std::find_if(accounts.begin(), accounts.end(), [login](User &user_tmp) {
        return user_tmp.getLogin() == login;
    });

    bool isSignIn = false;
    if (it == accounts.end()) {
        std::cout << kAccountNotFound << '\n';
    } else {
        std::string salt = (*it).getPassword().salt;
        std::string password;

        // This try - catch if user input ':quit' to cancel password Input
        try {
            password = InputPassword(std::cin, kInput + kPassword);
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
            std::cout << Paint(RED, kWrongPassword) << '\n';
        }
    }

    return isSignIn;
}

void SignUp(std::vector<User>& accounts) {
    const std::string& kSuccess = "Account successfully registered!";
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
    accounts.push_back(new_user);

    std::cout << Paint(GREEN, kSuccess) << '\n';
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
        // This is for edit
        const std::string& kPassword = "Password(':quit' - cancel): ";
        const std::string& kInput = "Input ";

        user.login_ = InputLogin(in);
        user.password_ = GenerateHashPassword(InputPassword(in, kInput + kPassword));
        user.access_ = InputAccess(in);
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const User &user) {
    out << user.login_ << ' ' << user.password_ << ' ' << user.access_;
    return out;
}
