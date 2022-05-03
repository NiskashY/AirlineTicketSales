#pragma once
#include <iostream>

#define CLEAR_LINE() (std::cout << "\033[2K")
#define GO_UP_LINE() (std::cout << "\033[1A")
#define GO_DOWN_LINE() (std::cout << "\033[1B")
#define GO_TO_COLUMN(num) (std::cout << "\033[" + std::to_string(num) + "G")

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET_COLOR "\033[0m"

std::string Paint(const std::string& color, const std::string& phrase);
