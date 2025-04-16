# Sistema de Mensageria Distribuída

Trabalho da disciplina de Computação Paralela e Distribuída - IFSP Hortolândia

## Descrição
Implementação de um sistema de mensageria distribuída com suporte a:
- Comunicação entre múltiplos nós
- Padrões unicast, multicast e broadcast
- Ordenação de mensagens com relógio lógico
- Logs de produção/consumo

## Tecnologias
- C++17
- Boost.Asio para rede
- CMake para build

## Como Compilar

```bash
mkdir build
cd build
cmake ..
make
