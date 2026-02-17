#include <iostream>
#include <boost/asio.hpp>
#include <spdlog/spdlog.h>
#include <memory>
using boost::asio::ip::tcp;

int main(){
    try {
        boost::asio::io_context io;

        // 1. Escuchar en el puerto 5555
        tcp::acceptor acceptor(io, tcp::endpoint(tcp::v4(), 5555));

        std::cout << "Server listening on port 5555...\n";

        // 2. Crear socket para el cliente
        tcp::socket socket(io);

        // 3. Bloquea hasta que alguien se conecta
        acceptor.accept(socket);

        std::cout << "Se conecto alguien esooow!\n";

        // 4. Buffer para recibir datos
        char data[1024];

        // 5. Leer datos (bloqueante)
        size_t length = socket.read_some(boost::asio::buffer(data));

        std::string received(data, length);
        std::cout << "Se recibio el mensaje este nose que es: " << received << "\n";

        // 6. Responder
        std::string response = "Si llego el mensaje qlia\n";
        boost::asio::write(socket, boost::asio::buffer(response));

        std::cout << "Se envio la respuesta, cerrando conexion\n";
    }
    catch (std::exception& e) {
        std::cerr << "Error qliao: " << e.what() << "\n";
    }
    // en
    return 0;

}
