#pragma once
#include <boost/asio.hpp>
#include <memory>
#include "mensagem.hpp"

using boost::asio::ip::tcp;

class ProxyCliente : public std::enable_shared_from_this<ProxyCliente> {
public:
    ProxyCliente(tcp::socket socket, const std::string& idCliente);
    
    void iniciar();
    void entregar(const Mensagem& msg);
    std::string obterId() const;

private:
    void ler();
    void processarMensagem(const std::string& dados);

    tcp::socket socket_;
    std::string idCliente_;
    enum { max_length = 1024 };
    char dados_[max_length];
};