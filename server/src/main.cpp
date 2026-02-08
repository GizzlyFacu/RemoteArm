#include <iostream>
#include <boost/asio.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/details/os.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
int main(){

    // Test spdlog
    /*
    spdlog::set_pattern("[%H:%M:%S.%e] [%l] %v");
    spdlog::info("Hola mundo desde spdlog 👋");
    spdlog::warn("Esto es un warning de prueba");
    spdlog::error("Esto es un error de prueba");
    */

    //auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");

    // 1. Crear sink de archivo
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
        "armserver.log", true // true = append
        );

    // 2. Crear logger con ese sink
    auto logger = std::make_shared<spdlog::logger>("armserver", file_sink);

    // 3. Registrar y setear como default
    spdlog::register_logger(logger);
    spdlog::set_default_logger(logger);

    // 4. Configuración básica
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%H:%M:%S] [%l] %v");

    // 5. Logs
    SPDLOG_INFO("Servidor iniciado");
    SPDLOG_DEBUG("Puerto TCP: {}", 5555);
    SPDLOG_ERROR("Error al conectar con ESP32");
    spdlog::info("Pepas");

    /*
    spdlog::logger logger ("custom logger",{console_sink});
    logger.info("some info log");
    logger.error("critical issue");

    // Test Boost.Asio
    boost::asio::io_context io;
    spdlog::info("Boost.Asio io_context creado correctamente");
*/

    return 0;

}
