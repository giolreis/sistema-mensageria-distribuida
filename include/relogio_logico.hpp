#pragma once
#include <atomic>
#include <string>

struct TimestampLamport {
    long contador;
    std::string idNo;
    
    bool operator<(const TimestampLamport& outro) const {
        return contador < outro.contador || 
              (contador == outro.contador && idNo < outro.idNo);
    }
};

class RelogioLamport {
public:
    RelogioLamport(const std::string& idNo) : idNo_(idNo) {}
    
    TimestampLamport obterTimestamp();
    void atualizar(TimestampLamport recebido);
    
private:
    std::atomic<long> contador_{0};
    std::string idNo_;
};