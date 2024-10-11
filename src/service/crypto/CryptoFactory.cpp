#include "CryptoFactory.hpp"

#include "magic_enum.hpp"
#include "service/crypto/CaesarCipher.hpp"
#include "service/crypto/XorCipher.hpp"
#include "service/crypto/IdentityCipher.hpp"

CryptoFactory::CryptoFactory()
	: m_CryptoMap{
		{CryptoAlgo::CAESAR,	[](int key) {return std::make_shared<CaesarCipher>(key); }},
		{CryptoAlgo::XOR,		[](int key) {return std::make_shared<XorCipher>(key); }},
		{CryptoAlgo::IDENTITY,	[](int key) {return std::make_shared<IdentityCipher>(key); }},
	}
{ }

std::shared_ptr<Crypto> CryptoFactory::GetCrypto(CryptoAlgo algo, int key)
{
	return m_CryptoMap[algo](key);
}

std::shared_ptr<Crypto> CryptoFactory::GetCrypto(const std::string& algo, int key)
{
	return GetCrypto(std::string_view{ algo }, key);
}

std::shared_ptr<Crypto> CryptoFactory::GetCrypto(std::string_view algo, int key)
{
	auto algoEnum = magic_enum::enum_cast<CryptoAlgo>(algo, magic_enum::case_insensitive);
	if (algoEnum.has_value())
	{
		return GetCrypto(algoEnum.value(), key);
	}
	else return nullptr;
}
