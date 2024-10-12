#pragma once

#include <string>
#include <string_view>

class ServerConfig
{
private:
    std::string m_Host;
    uint16_t m_Port;
public:
    ServerConfig(std::string_view host, uint16_t port) : m_Host{ host }, m_Port{ port } { }
    ServerConfig() : ServerConfig("0.0.0.0", 8000) { }
    ServerConfig(std::string_view filePath);

    inline std::string GetHost() const { return m_Host; }
    inline uint16_t GetPort() const { return m_Port; }
};
