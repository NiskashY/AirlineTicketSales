#pragma once
#include <string>
#include "user.h"

class Admin : public User {
private:
    // Template function for both flights and users acounts;
    template <class T>
    void DeleteInfo(Reader& reader, std::vector<T>& data) {
        const auto& kSuccess = "Done!";
        const auto& kInputPositions = "Input positions you want to delete:\n";
        const auto& kPos = "position #";

        reader.ReadFromFile(data);
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
        reader.DeleteObject(positions, data);

        std::cout << '\t' << kSuccess << '\n';
    }

public:
    Admin() = default;

    Admin(const std::string &login, const Password &password, Role &role)
            : User(login, password, role) {}


    // Data manipulation block
    void AddFlights();

    void DeleteFlights();

//    void EditFlights() {
//
//    }


};

