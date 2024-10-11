#pragma once

#include "service/crypto/Crypto.hpp"

class XorCipher : public Crypto {
public:
    using Crypto::Crypto;
    // XorCipher(int key) : Crypto(key) {}  // Constructor with key initialization

    // Overriding Encrypt and Decrypt methods
    std::string Encrypt(const std::string& data) override;
    std::string Decrypt(const std::string& data) override;
};