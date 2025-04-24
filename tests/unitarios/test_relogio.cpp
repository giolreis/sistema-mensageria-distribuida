// tests/unitarios/test_relogio.cpp
#include <gtest/gtest.h>
#include "../../include/relogio_logico.hpp"

TEST(RelogioLamportTest, OrdenacaoCorreta) {
    RelogioLamport relogio;
    auto t1 = relogio.obterTimestamp();
    auto t2 = relogio.obterTimestamp();
    ASSERT_TRUE(t1 < t2);
}