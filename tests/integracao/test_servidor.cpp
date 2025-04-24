// tests/integracao/test_servidor.cpp
#include <gtest/gtest.h>
#include "../../include/servidor_mensagens.hpp"

class ServidorTest : public ::testing::Test {
protected:
    void SetUp() override {
        servidor_ = ServidorMensagens::obterInstancia();
        servidor_->iniciar(1234);
    }
    
    ServidorMensagens* servidor_;
};

TEST_F(ServidorTest, BroadcastFunciona) {
    Mensagem msg("cli1", "broadcast", relogio_.obterTimestamp(), TipoMensagem::BROADCAST);
    servidor_->enviarBroadcast(msg);
    // Verificar se todos os clientes receberam
}