#include <iostream>
#include <string>
#include <boost/asio.hpp>

int main(){
    //estructua mental
    /*
main()
 ├── io_context
 ├── resolver
 ├── socket
 ├── resolve()
 ├── connect()
 ├── write()
 ├── (optional) read()
 └── close()
    */
    try {
        // Motor de eventos
        boost::asio::io_context io_context;

        // Resolver (traduce host + puerto a endpoint)
        boost::asio::ip::tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve("127.0.0.1", "5555");

        // Socket TCP
        boost::asio::ip::tcp::socket socket(io_context);

        // Conexión
        boost::asio::connect(socket, endpoints);

        // Enviar mensaje
        std::string message = "Hello Server\n";
        boost::asio::write(socket, boost::asio::buffer(message));

        //Ver respuesta de mi server
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\n");

        std::istream response_stream(&response);
        std::string reply;
        std::getline(response_stream, reply);

        std::cout << "Respuesta: " << reply << "\n";
        // Cerrar conexión
        socket.close();

        std::cout << "Mensaje enviado correctamente.\n";
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
