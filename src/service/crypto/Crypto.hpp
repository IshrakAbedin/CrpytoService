#pragma once

#include <string>

class Crypto {
protected:
    int m_Key;  // The key for encryption and decryption

public:
    Crypto(int key) : m_Key(key) {}  // Constructor with key initialization
    Crypto() : Crypto(5) {}  // Default Constructor
    virtual ~Crypto() {}  // Virtual destructor

    // Pure virtual methods for encryption and decryption
    virtual std::string Encrypt(const std::string& data) = 0;
    virtual std::string Decrypt(const std::string& data) = 0;
};
