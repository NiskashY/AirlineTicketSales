#include "core.h"

bool isNeedToExit() {
    const auto& kSure = "Are you sure you want to exit? 1 - yes, else - no";
    const auto& kChoice = "Your choice: ";
    std::cout << Paint(BACK_RED, kSure) << '\n' << kChoice;
    int isNeedToExit = 0;
    CheckNum(std::cin, isNeedToExit);
    if (isNeedToExit == 1) {
        return false;
    }
    return true;
}

void Core(std::vector<User>& accounts, std::vector<Flight>& flights) {
    bool isSignIn = false;
    User user;
    while (true) {
        system("cls");
        if (!isSignIn) {
            ShowStartMenu();
            int tmp = 0;
            CheckNum(std::cin, tmp);
            if (tmp == 1) { // 1 == Sign In
                if (SignIn(accounts, user)) {
                    isSignIn = true;
                }
            } else if (tmp == 2) {
                SignUp(accounts);
            } else {
                exit(EXIT_SUCCESS);
            }
        } else {
            if (user.getAccess() == 2 || user.getAccess() == 3) {
                ShowAdminMainMenu();
                int tmp = 0;
                CheckNum(std::cin, tmp );
                if (tmp == 1) {
                    AdminFlightSection(user, flights);
                } else if (tmp == 2) {
                    system("cls");
                    AdminAccountSection(user, accounts, flights);
                } else {
                    isSignIn = isNeedToExit();
                }
            } else {
                try { // exception occurs if the user select 'exit' (this function is only here)
                    DefaultUserFlightSection(flights, user);
                } catch( std::runtime_error& e) {
                    isSignIn = isNeedToExit();
                    continue;
                }
            }
        }
        system("pause");
    }
}

void DefaultUserFlightSection(std::vector<Flight>& flights, User& user, int tmp) {
    if (tmp == -1) { // when we do not provide tmp value from other function (for example main menu)
        ShowFlightsSection();
        const auto &kBack = "else - Back";
        const auto &kChoice = "Your choice: ";
        std::cout << kBack << '\n' << kChoice;
        CheckNum(std::cin, tmp);
        std::cout << '\n';
    }
    switch(tmp) {
        case 1: case 2: {
            user.ViewFlights(flights);

            std::cout << '\n';
            if (tmp == 2) {
                user.BuyTickets(flights);
            }
            break;
        }
        case 3: {
            auto result = user.SearchFlights();
            if (result.empty()) {
                const auto& kNotMatch = "No flights meets your requirements!";
                std::cout << Paint(YELLOW, kNotMatch) << '\n';
            } else {
                std::cout << '\n';
                user.ViewFlights(result);
            }
            break;
        }
        case 4: {
            std::cout << '\n';
            user.ViewFlights(user.SortFlights(flights));
            std::cout << '\n';
            break;
        }
        default : {
            throw std::runtime_error("back");
        }
    }
}

void AdminFlightSection(User &user, std::vector<Flight>& flights) {
    while (true) {
        system("cls");
        ShowAdminFLightsSection();
        int tmp = 0;
        CheckNum(std::cin, tmp);

        std::cout << '\n';
        switch (tmp) {
            case 1 : case 2: case 3: case 4 :{
                DefaultUserFlightSection(flights, user, tmp);
                break;
            }
            case 5: {
                user.ViewFlights(flights);
                DeleteFlights(flights);
                break;
            }
            case 6: {
                AddFlights(flights);
                break;
            }
            case 7: {
                user.ViewFlights(flights);
                EditFlights(flights);
                break;
            }
            default:
                return;
        }
        system("pause");
    }
}

void AdminAccountSection(User& user, std::vector<User>& accounts, std::vector<Flight>& flights) {
    while (true) {
        system("cls");
        ShowAdminAccountsSection();
        int tmp = 0;
        CheckNum(std::cin, tmp);
        std::cout << '\n';
        switch (tmp) {
            case 1: case 3:  {
                ViewUsers(accounts);
                std::cout << '\n';
                if (tmp == 3) {
                    int position = 0;
                    position = InputEditedPosition();
                    EditAccount(user, position, accounts);
                }
                break;
            }
            case 2: {
                const auto& kNewUser = "NEW USER:";
                const std::string& kSuccess = "Account successfully added!";

                std::cout << Paint(YELLOW, kNewUser) << '\n';
                try {
                    AddUser(accounts, CreateNewUser(accounts));
                } catch(std::runtime_error& e) {
                    std::cout << Paint(BLUE, "back")     << '\n';
                    break;
                }
                std::cout << Paint(GREEN, kSuccess) << '\n';
                break;
            }
            case 4 : {
                const auto& kSection = "\n----Delete Section---\n";
                ViewUsers(accounts);
                std::cout << Paint(YELLOW, kSection);
                std::string login = InputLogin(std::cin);
                DeleteAccount(user, accounts, login);
                break;
            }
            case 5: {
                int parameter = 0, min_parameter = 0, max_parameter = 5;
                ShowAccountMenuSort();
                CheckNum(std::cin, parameter);
                if (parameter > min_parameter && parameter < max_parameter) { // parameter can be from 1 to 4, else - exit
                    std::cout << '\n';
                    ViewUsers(SortAccounts(accounts, parameter));
                }
                break;
            }
            default:
                return;
        }
        system("pause");
    }
}

void ReadFiles(std::vector<User> &accounts, std::vector<Flight> &flights) {
    Reader accountsReader(ALL_USER_ACCOUNTS);
    Reader flightsReader(FLIGHTS_DATABASE);

    accountsReader.ReadFromFile(accounts);
    flightsReader.ReadFromFile(flights);

    if (accounts.empty()) {
        // if in accounts file empty - add Main Admin
        User main_admin("admin", GenerateHashPassword("adminadmin"), 3);
        accountsReader.AddObject(main_admin);
        accounts.push_back(main_admin);
    }
}
