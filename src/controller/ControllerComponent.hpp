#pragma once

#include "oatpp/core/macro/component.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "service/crypto/CryptoFactory.hpp"

/**
 *  Class which creates and holds Controller components and registers components in oatpp::base::Environment
 *  Order of components initialization is from top to bottom
 */
class ControllerComponent {
public:
	/**
	 *  Create ObjectMapper component to serialize/deserialize DTOs in Contoller's API
	 */
	OATPP_CREATE_COMPONENT(std::shared_ptr<oatpp::data::mapping::ObjectMapper>, apiObjectMapper)([] {
		return oatpp::parser::json::mapping::ObjectMapper::createShared();
		}());
	/**
	 *  Create Crypto Factory component
	 */
	OATPP_CREATE_COMPONENT(std::shared_ptr<CryptoFactory>, cryptoFactory)([] {
		return std::make_shared<CryptoFactory>();
		}());

};
