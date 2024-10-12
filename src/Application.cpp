#include "ServerConfig.hpp"
#include "AppComponent.hpp"
#include "controller/ControllerComponent.hpp"
#include "controller/CryptoController.hpp"
#include "controller/MyController.hpp"

#include "oatpp/network/Server.hpp"

constexpr auto CONFIG_FILE_PATH = "./config.toml";

static void run() {

    /* Create a server configuration from file */
    ServerConfig config{ CONFIG_FILE_PATH };

    /* Register Components in scope of run() method */
    AppComponent appComponents{ config };
    ControllerComponent controllerComponents;

    /* Get router component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    /* Create MyController and add all of its endpoints to router */
    router->addController(std::make_shared<MyController>());
    router->addController(std::make_shared<CryptoController>());

    /* Get connection handler component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

    /* Get connection provider component */
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

    /* Create server which takes provided TCP connections and passes them to HTTP connection handler */
    oatpp::network::Server server(connectionProvider, connectionHandler);

    /* Print info about server host and port */
    OATPP_LOGI("CryptoService", "Server running on <%s:%s>",
        connectionProvider->getProperty("host").std_str().c_str(),
        connectionProvider->getProperty("port").std_str().c_str()
    );

    /* Run server */
    server.run();
}

int main() {

    /* Init oatpp Environment */
    oatpp::base::Environment::init();

    /* Run App */
    run();

    /* Destroy oatpp Environment */
    oatpp::base::Environment::destroy();

    return 0;
}