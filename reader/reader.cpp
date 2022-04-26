#include "reader.h"

bool Reader::isFileNotEmpty() const {
    std::ofstream file(kFileName_, std::ios::app);
    bool isFileNotEmpty = file.tellp();
    file.close();
    return isFileNotEmpty;
}
