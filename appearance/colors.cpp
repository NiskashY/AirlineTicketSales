#include "colors.h"

std::string Paint(const std::string &color, const std::string &phrase) {
    return color + phrase + RESET_COLOR;
}

void CLEAR_LINES(const int &amount) {
    for (int i = 0; i < amount; ++i) {
        CLEAR_LINE();
        GO_UP_LINE();
    }
}
