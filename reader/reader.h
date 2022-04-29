#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#include "../check_num.h"

#define ERROR_OPEN_FILE "ERROR: failed to open file"
#define FILE_IS_EMPTY "FILE: empty file"

// Файл flights_database.txt находится в папке cmake-build-debug

class Reader {
private:
    const std::string kFileName_;

public:

    explicit Reader(const std::string& kFileName) : kFileName_(kFileName) {}

    bool isFileNotEmpty() const;

    template <class T>
    void AddObject(const T& object) {
        std::ofstream file(kFileName_, std::ios::app);
        if (!file.is_open()) {
            std::cout << ERROR_OPEN_FILE  << '\n';
        } else {
            if (isFileNotEmpty()) {
                file << '\n';
            }
            file << object;
        }
        file.close();
    }

    template <class T>
    void AddSeveralObjects(const std::vector<T>& data) {
        for (const auto& item : data) {
            AddObject(item);
        }
    }

    template <class T>
    void ReadFromFile(std::vector<T>& data, bool isNeedToShowMessage = true) const {
        std::ifstream in (kFileName_, std::ios::in);
        if (!in.is_open() && isNeedToShowMessage) {
            std::cout << ERROR_OPEN_FILE << '\n';
        } else {
            if (isFileNotEmpty()) {
                while (!in.eof()) {
                    T tmp;
                    in >> tmp;
                    data.push_back(tmp);
                }
            } else if (isNeedToShowMessage) {
                std::cout << FILE_IS_EMPTY << '\n';
            }
        }
        in.close();
    }

    template <class T>
    void WriteIntoFile(const std::vector<T>& data) const { // delete old information
        std::ofstream out(kFileName_, std::ios::out);
        if (!out.is_open()) {
            std::cout << ERROR_OPEN_FILE << '\n';
        } else {
            bool isFirst = true;
            for (auto &item: data) {
                if (!isFirst) {
                    out << '\n';
                }
                isFirst = false;
                out << item;
            }
        }
        out.close();
    }

    template <class T>
    void DeleteObject(const std::vector<int>& positions, std::vector<T>& data) {
        const auto& kSuccessDelete = "The Information successfully deleted!";
        const auto& kInvalidNumber = "The Information with this number does not exist or already deleted";
        const auto& kWarning = "\x1b[31mWARNING: are you sure you want to delete ";
        const auto& kWarningMenu = "'YES' - i want delete\n'Root-YES' - I want to delete, but no longer ask for confirmation\n"
                               "'quit' - leave\n else - skip\x1b[0m\nYour Choice:\t";

        // TODO: add const string to strings below
        bool isErased = false;
        bool isNeedToWarning = true;

        int successfully_deleted = 0;

        for (int position : positions) {
            auto it = data.begin() + position - 1 - successfully_deleted;
            const auto& kStrPosition = "<position #" + std::to_string(position) + ">  - ";
            if (it < data.end() && it >= data.begin()) {
                std::string request;
                if (isNeedToWarning) { // WARNING CHECK
                    std::cout << kWarning << kStrPosition << "?\n" << kWarningMenu ;
                    std::cin >> request;
                }

                if (request == "YES" || !isNeedToWarning || request == "Root-YES") {
                    data.erase(it);
                    std::cout << kStrPosition << kSuccessDelete << '\n';
                    isErased = true;

                    if (request == "Root-YES") {
                        isNeedToWarning = false;
                    }

                    ++successfully_deleted;
                } else if (request == "quit") {
                    return;
                }
            } else {
                std::cout << kStrPosition << "\x1b[31m" << kInvalidNumber << "\x1b[0m\n";
            }
        }

        if (isErased) { // if at least once we erase something from data
            WriteIntoFile(data);
        }
    }

    template <class T>
    void Edit(const int& position, std::vector<T>& data) {
        const auto& kSuccessEdit = "The Information successfully edited!";
        const auto& kInvalidNumber = "The Information with this number does not exist";

        const auto& kNewInfo = "Input new information:";
        std::cout << "\n" << kNewInfo << "\n";
        T new_info;
        std::cin >> new_info;
        if (position < data.size() && position >= 0) {
            data[position] = new_info;
            WriteIntoFile(data);
            std::cout << kSuccessEdit << '\n';
        } else {
            std::cout << kInvalidNumber << '\n';
        }

    }

};
