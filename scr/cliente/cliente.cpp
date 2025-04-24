#include "proxy_cliente.hpp"
#include <boost/asio.hpp>
#include <iostream>

ProxyCliente::ProxyCliente(tcp::socket socket, const std::string& idCliente)
    : socket_(std::move(socket)), idCliente_(idCliente) {}

void ProxyCliente::iniciar() {
    ler();
}

void ProxyCliente::entregar(const Mensagem& msg) {
    std::string dados = msg.serializar();
    boost::asio::write(socket_, boost::asio::buffer(dados));
}

// Implementações dos outros métodos...