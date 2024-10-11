#include "XorCipher.hpp"

#include <sstream>

std::string XorCipher::Encrypt(const std::string& data)
{
    std::stringstream ss;
    for (char c : data) {
        ss << static_cast<char>(c ^ m_Key);  // XOR each character with the key
    }
    return ss.str();
}

std::string XorCipher::Decrypt(const std::string& data)
{
    return Encrypt(data);
}
