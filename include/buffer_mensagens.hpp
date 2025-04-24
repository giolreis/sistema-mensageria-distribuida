#pragma once
#include <deque>
#include <mutex>
#include <fstream>
#include "mensagem.hpp"
#include "logger.hpp"

class BufferMensagens {
public:
    BufferMensagens() : logger_("mensagens.log") {}
    
    void adicionar(const Mensagem& msg);
    Mensagem remover(const std::string& consumidor);
    bool vazio() const;

private:
    std::deque<Mensagem> buffer_;
    mutable std::mutex mutex_;
    Logger logger_;
};