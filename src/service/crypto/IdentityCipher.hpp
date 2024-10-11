#pragma once

#include "service/crypto/Crypto.hpp"

class IdentityCipher : public Crypto {
public:
    using Crypto::Crypto;
    // CaesarCipher(int key) : Crypto(key) {}  // Constructor with key initialization

    // Overriding Encrypt and Decrypt methods
    std::string Encrypt(const std::string& data) override;
    std::string Decrypt(const std::string& data) override;
};
