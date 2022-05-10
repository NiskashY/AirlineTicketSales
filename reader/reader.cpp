#include "reader.h"

bool Reader::isFileNotEmpty() const {
    std::ifstream file(kFileName_);
    bool isFileNotEmpty = (file.peek() != std::ifstream::traits_type::eof());
    file.close();
    return isFileNotEmpty;
}

int InputNumberOfDeleted() {
    const auto& kInputNumber = "Input amount of deleting elements: ";
    const auto &kInvalidAmount = "Amount cant be less then 0. ReEnter: ";
    const int &kMinValue = 0;

    std::cout << kInputNumber;
    int amount = 0;
    do {
        CheckNum(std::cin, amount);
        if (amount < kMinValue) {
            std::cout << kInvalidAmount << '\n';
        }
    } while (amount < kMinValue);

    return amount;
}
