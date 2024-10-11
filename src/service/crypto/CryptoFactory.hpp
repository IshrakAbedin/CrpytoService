#pragma once

#include <functional>
#include <memory>
#include <string_view>
#include <unordered_map>

#include "Crypto.hpp"

enum class CryptoAlgo
{
	CAESAR, XOR, IDENTITY
};

class CryptoFactory
{
private:
	using MapReturn_t = std::function<std::shared_ptr<Crypto>(int)>;
	std::unordered_map<CryptoAlgo, MapReturn_t> m_CryptoMap;
public:
	CryptoFactory();
	std::shared_ptr<Crypto> GetCrypto(CryptoAlgo algo, int key = 5);
	std::shared_ptr<Crypto> GetCrypto(const std::string& algo, int key = 5);
	std::shared_ptr<Crypto> GetCrypto(std::string_view algo, int key = 5);
};
