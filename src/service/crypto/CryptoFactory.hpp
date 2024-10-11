#pragma once

#include <memory>

#include "Crypto.hpp"

enum class CryptoAlgo
{
	CAESAR, XOR, IDENTITY
};

class CryptoFactory
{
private:
	CryptoFactory() = delete;
public:
	static std::shared_ptr<Crypto> GetCrypto(CryptoAlgo algo, int key = 5);
};