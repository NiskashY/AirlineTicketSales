#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

#define ERROR_OPEN_FILE "ERROR: failed to open file"

// Файл flights_database.txt находится в папке cmake-build-debug

class Reader {
private:
    const std::string kFileName_;

public:
    explicit Reader(const std::string& kFileName) : kFileName_(kFileName) {}

    template <class T>
    void AddObject(const T& object) {
        std::ofstream file(kFileName_, std::ios::app);
        if (!file.is_open()) {
            std::cout << ERROR_OPEN_FILE << '\n';
        } else {
            file << '\n' << object;
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
    void ReadFromFile(std::vector<T>& data) const {
        std::ifstream in (kFileName_, std::ios::in);
        if (!in.is_open()) {
            std::cout << ERROR_OPEN_FILE << '\n';
        } else {
            while (!in.eof()) {
                T tmp;
                in >> tmp;
                data.push_back(tmp);
            }
        }
        in.close();
    }

    template <class T>
    void WriteIntoFile(const std::vector<T>& data) const {
        std::ofstream out(kFileName_, std::ios::out);
        if (!out.is_open()) {
            std::cout << ERROR_OPEN_FILE << '\n';
        } else {
            for (auto &item: data) {
                out << '\n' << item;
            }
        }
        out.close();
    }

    template <class T>
    void DeleteObject(const std::vector<int>& positions, std::vector<T>& data) {
        const auto& kSuccessDelete = "The Information successfully deleted!";
        const auto& kInvalidNumber = "The Information with this number does not exist";

        for (int position : positions) {
            auto it = data.begin() + position - 1;
            if (it < data.end() && it >= data.begin()) {
                data.erase(it);
                std::cout << "<position #" << position << ">  - " << kSuccessDelete << '\n';
            } else {
                std::cout << "<position #" << position << ">  - " << "\x1b[31m" << kInvalidNumber << "\x1b[0m\n";
            }
        }
        WriteIntoFile(data);
    }

    template <class T>
    bool Edit(const int& position, std::vector<T>& data) {
        const auto& kNewInfo = "Input new information:";
        std::cout << "\n" << kNewInfo << "\n";
        T new_info;
        std::cin >> new_info;
        if (position < data.size() && position >= 0) {
            data[position] = new_info;
            WriteIntoFile(data);
            return true;
        }
        return false;
    }

};

