#include "colors.h"

std::string Paint(const std::string &color, const std::string &phrase) {
    return color + phrase + RESET_COLOR;
}
