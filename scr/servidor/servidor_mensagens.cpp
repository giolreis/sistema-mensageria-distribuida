#include "servidor_mensagens.hpp"
#include <boost/asio.hpp>
#include <iostream>

ServidorMensagens* ServidorMensagens::instancia_ = nullptr;

ServidorMensagens* ServidorMensagens::obterInstancia() {
    if (!instancia_) {
        instancia_ = new ServidorMensagens();
    }
    return instancia_;
}

void ServidorMensagens::iniciar(unsigned short porta) {
    try {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), porta));
        
        while (true) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            
            char dados[1024];
            size_t length = socket.read_some(boost::asio::buffer(dados));
            std::string msg(dados, length);
            
            if (msg.find("REGISTRO:") == 0) {
                std::string idCliente = msg.substr(9);
                auto proxy = std::make_shared<ProxyCliente>(std::move(socket), idCliente);
                registrarCliente(proxy);
                proxy->iniciar();
            }
        }
    } catch (std::exception& e) {
        std::cerr << "Erro no servidor: " << e.what() << "\n";
    }
}

// Implementações dos outros métodos...