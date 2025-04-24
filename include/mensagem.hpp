#pragma once
#include <string>
#include "relogio_logico.hpp"

enum class TipoMensagem {
    UNICAST,
    BROADCAST,
    MULTICAST
};

struct Mensagem {
    std::string remetente;
    std::string conteudo;
    TimestampLamport timestamp;
    TipoMensagem tipo;
    std::string destinatario;  // Para unicast
    std::string canal;         // Para multicast
    
    std::string serializar() const;
    static Mensagem desserializar(const std::string& dados);
};