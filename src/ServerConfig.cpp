#include "ServerConfig.hpp"

#include <iostream>

#define TOML_HEADER_ONLY 0
#include "toml++/toml.hpp"

ServerConfig::ServerConfig(std::string_view filePath)
{
    try
    {
        auto config = toml::parse_file(filePath);

        m_Host = config["server"]["host"].value_or("0.0.0.0");
        m_Port = config["server"]["port"].value_or(8000);
    }
    catch (const std::exception& e)
    {
        std::cerr << "[Config ERROR!] " << e.what() << '\n';
        m_Host = "0.0.0.0";
        m_Port = 8000;
    }
}
