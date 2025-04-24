#pragma once
#include <fstream>
#include <mutex>
#include <string>
#include "mensagem.hpp"

class Logger {
public:
    Logger(const std::string& arquivo);
    void registrarProducao(const Mensagem& msg);
    void registrarConsumo(const std::string& consumidor, const Mensagem& msg);

private:
    std::ofstream arquivo_;
    std::mutex mutex_;
};