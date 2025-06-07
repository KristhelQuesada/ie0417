// Sirve para unit testing
#include <gtest/gtest.h>
#include "2_calculator.h"


class CalculatorTest : public ::testing::Test {
    protected:
        Calculator calc;

        void SetUp() override {
            // Configuracion comun que se necesita antes de cada test
            // Por ejemplo, si quisieramos probas operaciones dentro de
            // una base de datos, pero si esta esta vacia, aca podriamos
            // definir una logica que llene la base de datos para
            // trabajar con ella
        }

        void TearDown() override {
            // Limpieza comun que se necesita despues de cada teste
            // Asimismo, liego de hacer el testing, siguiendo con el
            // ejemplo de la base de datos, si quisieramos limpiar
            // los cambios que hicimos para que no me quede basura
            // dentro de la DB, aca es donde lo hariamos.
        }

};

// Prueba para el modulo Add usando TestFixture
TEST_F(CalculatorTest, AddTest) {
    EXPECT_EQ(calc.Add(1, 1), 2);
    EXPECT_EQ(calc.Add(-1, 1), 0);
    EXPECT_EQ(calc.Add(-1, -1), -2);
}

// Prueba para el modulo Add usando TestFixture
TEST_F(CalculatorTest, SubstractTest) {
    EXPECT_EQ(calc.Substract(2, 1), 1);
    EXPECT_EQ(calc.Substract(-1, 1), -2);
    EXPECT_EQ(calc.Substract(-1, -1), 0);
}

// Se agrega prueba con assert para observar su comportamiento
// Se fuerza un errpr con el assert
// Se espera que el expect no se ejecute por el fallo
// [Info] Descomente para visualizar el ejemplo
//TEST_F(CalculatorTest, FailingTest) {
//    ASSERT_EQ(calc.Add(2, 2), 5);  // Falla porque 2+2 != 5
//    EXPECT_EQ(calc.Substract(2, 1), 1);
//}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}