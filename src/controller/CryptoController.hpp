#pragma once

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "controller/ControllerComponent.hpp"
#include "dto/CryptoDTO.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

class CryptoController : public oatpp::web::server::api::ApiController {
public:
	/**
	 * Constructor with object mapper.
	 * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
	 */
	CryptoController(OATPP_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, objectMapper))
		: oatpp::web::server::api::ApiController(objectMapper)
	{}
public:

	ENDPOINT("GET", "/encrypt", encrypt,
		QUERY(String, algorithm, "algorithm"),
		QUERY(Int32, key, "key"),
		QUERY(String, text, "text"))
	{
		OATPP_LOGI("Encryption Endpoint",
			"Received request with algorithm='%s', key='%d', and text='%s'",
			algorithm->c_str(), static_cast<int>(key), text->c_str());

		OATPP_COMPONENT(std::shared_ptr<CryptoFactory>, cryptoFactory);

		auto crypto = cryptoFactory->GetCrypto(algorithm, key);

		if (crypto)
		{
			auto dto = CryptoDto::createShared();
			dto->statusCode = 200;
			dto->key = key;
			dto->algorithm = algorithm;
			dto->text = crypto->Encrypt(text);
			return createDtoResponse(Status::CODE_200, dto);
		}
		else
		{
			auto dto = CryptoDto::createShared();
			dto->statusCode = 400;
			dto->key = key;
			dto->algorithm = algorithm;
			dto->text = "Algorithm implementation not found!";
			return createDtoResponse(Status::CODE_400, dto);
		}
	}

	ENDPOINT("GET", "/decrypt", decrypt,
		QUERY(String, algorithm, "algorithm"),
		QUERY(Int32, key, "key"),
		QUERY(String, text, "text"))
	{
		OATPP_LOGI("Decryption Endpoint",
			"Received request with algorithm='%s', key='%d', and text='%s'",
			algorithm->c_str(), static_cast<int>(key), text->c_str());

		OATPP_COMPONENT(std::shared_ptr<CryptoFactory>, cryptoFactory);

		auto crypto = cryptoFactory->GetCrypto(algorithm, key);

		if (crypto)
		{
			auto dto = CryptoDto::createShared();
			dto->statusCode = 200;
			dto->key = key;
			dto->algorithm = algorithm;
			dto->text = crypto->Decrypt(text);
			return createDtoResponse(Status::CODE_200, dto);
		}
		else
		{
			auto dto = CryptoDto::createShared();
			dto->statusCode = 400;
			dto->key = key;
			dto->algorithm = algorithm;
			dto->text = "Algorithm implementation not found!";
			return createDtoResponse(Status::CODE_400, dto);
		}
	}

};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen