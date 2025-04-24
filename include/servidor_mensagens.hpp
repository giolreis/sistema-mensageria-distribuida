#pragma once
#include <boost/asio.hpp>
#include <map>
#include <memory>
#include <mutex>
#include "mensagem.hpp"
#include "buffer_mensagens.hpp"
#include "proxy_cliente.hpp"

using boost::asio::ip::tcp;

class ServidorMensagens {
public:
    static ServidorMensagens* obterInstancia();
    
    void iniciar(unsigned short porta);
    void registrarCliente(std::shared_ptr<ProxyCliente> proxy);
    void removerCliente(const std::string& idCliente);
    
    void enviarUnicast(const Mensagem& msg);
    void enviarBroadcast(const Mensagem& msg);
    void enviarMulticast(const Mensagem& msg, const std::string& canal);

private:
    ServidorMensagens() = default;
    static ServidorMensagens* instancia_;
    
    std::map<std::string, std::shared_ptr<ProxyCliente>> clientes_;
    std::map<std::string, std::vector<std::string>> canais_;
    BufferMensagens buffer_;
    
    std::mutex mutexClientes_;
    std::mutex mutexCanais_;
};