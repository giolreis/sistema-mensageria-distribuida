cmake_minimum_required(VERSION 3.10)
project(MessageBusIFSP)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system)
find_package(GTest REQUIRED)

# Servidor
add_executable(servidor 
    src/servidor/servidor_mensagens.cpp
    src/servidor/main.cpp
    src/comum/buffer_mensagens.cpp
    src/comum/logger.cpp
    src/comum/relogio_logico.cpp
)
target_link_libraries(servidor Boost::system pthread)

# Cliente
add_executable(cliente
    src/cliente/cliente.cpp
    src/cliente/main.cpp
)
target_link_libraries(cliente Boost::system)

# Testes
enable_testing()
add_executable(teste_unitario
    tests/unitarios/test_relogio.cpp
    src/comum/relogio_logico.cpp
)
target_link_libraries(teste_unitario GTest::GTest)
add_test(NAME teste_unitario COMMAND teste_unitario)