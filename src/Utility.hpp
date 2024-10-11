#pragma once

#include <sstream>
#include <iomanip>

std::string decodeUrl(const std::string& encodedStr) {
    std::string decodedStr;
    char ch;
    int i, ii;
    for (i = 0; i < encodedStr.length(); i++) {
        if (encodedStr[i] == '%') {
            sscanf(encodedStr.substr(i + 1, 2).c_str(), "%x", &ii);
            ch = static_cast<char>(ii);
            decodedStr += ch;
            i += 2;
        }
        else if (encodedStr[i] == '+') {
            decodedStr += ' ';
        }
        else {
            decodedStr += encodedStr[i];
        }
    }
    return decodedStr;
}