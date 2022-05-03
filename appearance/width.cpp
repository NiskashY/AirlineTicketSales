#include "width.h"

std::string width::CenterString(const std::string &str, const int &width) {
    int center_width = width / 2 - (int) str.length() / 2;
    std::string before_str(center_width, ' ');
    std::string after_str(width - center_width - str.length(), ' ');

    return before_str + str + after_str;
}
