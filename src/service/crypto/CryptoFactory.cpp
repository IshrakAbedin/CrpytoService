#include "CryptoFactory.hpp"

#include "service/crypto/CaesarCipher.hpp"
#include "service/crypto/XorCipher.hpp"
#include "service/crypto/IdentityCipher.hpp"

std::shared_ptr<Crypto> CryptoFactory::GetCrypto(CryptoAlgo algo, int key)
{
	switch (algo)
	{
	case CryptoAlgo::CAESAR:
		return std::make_shared<CaesarCipher>(key);
	case CryptoAlgo::XOR:
		return std::make_shared<XorCipher>(key);
	case CryptoAlgo::IDENTITY:
		return std::make_shared<IdentityCipher>(key);
	default:
		return std::make_shared<IdentityCipher>(key);
	}
}
