#include "core.h"

void getch() {  // this is for linux-clion to prevent immediately closing after work is done.
    std::string a;
    std::cout << "\nPress enter to continue... ";
    std::cin.get();
    getline(std::cin, a);
}

void Core(std::vector<User>& accounts, std::vector<Flight>& flights) {
    bool isSignIn = false;
    User user;
    while (true) {
        system("clear");
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
                continue;
            } else {
                exit(EXIT_SUCCESS);
            }
        } else {
            if (user.getAccess() == 2) {
                ShowAdminMainMenu();
                int tmp = 0;
                CheckNum(std::cin, tmp );
                if (tmp == 1) {
                    AdminFlightSection(user, flights);
                } else if (tmp == 2) {
                    system("clear");
                    AdminAccountSection(accounts, flights);
                } else {
                    isSignIn = false;
                }
            } else {
                DefaultUserFlightSection(flights, user);
            }
        }
        getch();
    }
}

void DefaultUserFlightSection(std::vector<Flight>& flights, User& user, int tmp) {
    if (tmp == -1) { // when we do not provide tmp value from other function (for example main menu)
        ShowFlightsSection();
        const auto &kBack = "else - Back";
        const auto &kChoice = "Your choice: ";
        std::cout << kBack << '\n' << kChoice;
        CheckNum(std::cin, tmp);
    }
    switch(tmp) {
        case 1: case 2: {
            user.ViewFlights(flights);
            if (tmp == 2) {
                user.BuyTickets(flights);
            }
            break;
        }
        case 3: {
            auto result = user.SearchFlights();
            if (result.empty()) {
                const auto& kNotMatch = "No flights meets your requirements!";
                std::cout << kNotMatch << '\n';
            }
            ShowFlights(result);
            break;
        }
        case 4: {
            auto result = user.SortFlights(flights);
            ShowFlights(result);
            break;
        }
        default : {
            return;
        }
    }
}

void AdminFlightSection(User &user, std::vector<Flight>& flights) {
    while (true) {
        system("clear");
        ShowAdminFLightsSection();
        int tmp = 0;
        CheckNum(std::cin, tmp);
        switch (tmp) {
            case 1 : case 2: case 3: case 4 :{
                DefaultUserFlightSection(flights, user, tmp);
                break;
            }
            case 5: {
                ShowFlights(flights);
                DeleteFlights(flights);
                break;
            }
            case 6: {
                AddFlights(flights);
                break;
            }
            case 7: {
                EditFlights(flights);
                break;
            }
            default:
                return;
        }
        getch();
    }
}

void AdminAccountSection(std::vector<User>& accounts, std::vector<Flight>& flights) {
    while (true) {
        system("clear");
        ShowAdminAccountsSection();
        int tmp = 0;
        CheckNum(std::cin, tmp);
        switch (tmp) {
            case 1 : {
                std::string login = InputLogin(std::cin);
                DeleteAccount(accounts, login);
                break;
            }
            case 2: {
                AddUser(accounts, CreateNewUser(accounts));
                break;
            }
            case 3: case 4:  {
                ViewUsers(accounts);
                if (tmp == 3) {
                    const auto &kInput = "Input position you want to edit: ";
                    int position = 0;
                    std::cout << kInput;
                    CheckNum(std::cin, position);
                    EditAccount(position, accounts);
                }
                break;
            }
            case 5: {
                int parameter = 0;
                ShowAccountMenuSort();
                CheckNum(std::cin, parameter);
                SortAccounts(accounts, parameter);
                ViewUsers(accounts);
                break;
            }
            default:
                return;
        }
        getch();
    }
}
