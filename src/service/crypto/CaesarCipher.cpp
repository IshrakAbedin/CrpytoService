#include "CaesarCipher.hpp"

#include <sstream>

std::string CaesarCipher::Encrypt(const std::string& data)
{
    std::stringstream ss;
    for (char c : data) {
        ss << static_cast<char>((c + m_Key - 'a') % 26 + 'a');  // Shift character by key
    }
    return ss.str();
}

std::string CaesarCipher::Decrypt(const std::string& data)
{
    std::stringstream ss;
    for (char c : data) {
        ss << static_cast<char>((c - m_Key - 'a' + 26) % 26 + 'a');  // Reverse the shift by key
    }
    return ss.str();
}
