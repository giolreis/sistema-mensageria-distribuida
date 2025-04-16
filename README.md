# Sistema de Mensageria Distribuída

![C++](https://img.shields.io/badge/C++-17-blue)
![Boost](https://img.shields.io/badge/Boost-Asio-orange)
![CMake](https://img.shields.io/badge/CMake-3.10+-brightgreen)
![License](https://img.shields.io/badge/License-MIT-green)

Trabalho da disciplina de Computação Paralela e Distribuída - IFSP Hortolândia

## Descrição
Implementação de um sistema de mensageria distribuída com suporte a:
- Comunicação entre múltiplos nós
- Padrões unicast, multicast e broadcast
- Ordenação de mensagens com relógio lógico (Lamport)
- Logs de produção/consumo para rastreamento
- Persistência de mensagens em arquivo

## Tecnologias
- C++17
- Boost.Asio para comunicação de rede
- CMake para sistema de build
- Git para controle de versão

## Equipe
|      Nome        | Prontuário |         Função         |
|------------------|------------|------------------------|
| Adilson Medeiros |  HT3038017 | Desenvolvedor e Tester |
| Giovani Reis     |  HT303786X | Desenvolvedor e Tester |

## Como Compilar

### Pré-requisitos
- Compilador C++17 (g++ ou clang)
- Boost.Asio instalado
- CMake 3.10+

```bash
# Clone o repositório
git clone https://github.com/seu-usuario/message-bus-ifsp.git](https://github.com/giolreis/sistema-mensageria-distribuida.git)
cd message-bus-ifsp

# Compilação
mkdir build
cd build
cmake ..
make

# Executar servidor
./src/servidor/servidor_mensagens

# Executar cliente (em outro terminal)
./src/cliente/cliente_mensagens <ID_CLIENTE>
