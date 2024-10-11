#pragma once

#include "magic_enum.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "dto/CryptoDTO.hpp"
#include "service/crypto/CryptoFactory.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin Codegen

class CryptoController : public oatpp::web::server::api::ApiController {
public:
	/**
	 * Constructor with object mapper.
	 * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
	 */
	CryptoController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
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

		auto dto = CryptoDto::createShared();
		dto->statusCode = 200;
		dto->key = key;
		dto->algorithm = algorithm;

		auto crypto = CryptoFactory::GetCrypto
		(
			magic_enum::enum_cast<CryptoAlgo>
			(
				algorithm->c_str(),
				magic_enum::case_insensitive
			).value_or(CryptoAlgo::IDENTITY),
			key
		);

		dto->text = crypto->Encrypt(text);

		return createDtoResponse(Status::CODE_200, dto);
	}

	ENDPOINT("GET", "/decrypt", decrypt,
		QUERY(String, algorithm, "algorithm"),
		QUERY(Int32, key, "key"),
		QUERY(String, text, "text"))
	{
		OATPP_LOGI("Decryption Endpoint",
			"Received request with algorithm='%s', key='%d', and text='%s'",
			algorithm->c_str(), static_cast<int>(key), text->c_str());

		auto dto = CryptoDto::createShared();
		dto->statusCode = 200;
		dto->key = key;
		dto->algorithm = algorithm;

		auto crypto = CryptoFactory::GetCrypto
		(
			magic_enum::enum_cast<CryptoAlgo>
			(
				algorithm->c_str(),
				magic_enum::case_insensitive
			).value_or(CryptoAlgo::IDENTITY),
			key
		);

		dto->text = crypto->Decrypt(text);

		return createDtoResponse(Status::CODE_200, dto);
	}

};

#include OATPP_CODEGEN_END(ApiController) ///< End Codegen