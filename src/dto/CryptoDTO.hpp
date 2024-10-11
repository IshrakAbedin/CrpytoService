#pragma once

#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

/* Begin DTO code-generation */
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * Message Data-Transfer-Object
 */
class CryptoDto : public oatpp::DTO {

	DTO_INIT(CryptoDto, DTO)
	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, algorithm);
	DTO_FIELD(Int32, key);
	DTO_FIELD(String, text);
};

/* TODO - Add more DTOs here */

/* End DTO code-generation */
#include OATPP_CODEGEN_END(DTO)