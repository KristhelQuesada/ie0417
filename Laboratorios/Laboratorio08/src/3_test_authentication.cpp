// test_authentication.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "3_authentication.h"
#include "3_mock_database.h"

using ::testing::Return;

// Este archivo demuestra cómo utilizar Google Mock para realizar pruebas unitarias
// sobre una clase de autenticación sin depender de una base de datos real.
// En lugar de usar la implementación original de la base de datos, se utiliza un 
// mock (simulacro) que imita su comportamiento. Esto permite:
// - Controlar las respuestas de los métodos de la base de datos, simulando distintos escenarios.
// - Validar que los métodos de autenticación (como login y registerUser) respondan correctamente
//   según el flujo esperado.
// - Ejecutar pruebas de forma rápida, aislada y reproducible, sin necesidad de recursos externos.
// Gracias a los `EXPECT_CALL` se pueden definir los valores que debería retornar el mock (db),
// y luego verificar si la lógica de autenticación se comporta como se espera ante esos valores.

TEST(AuthenticationTest, LoginSuccess) {
    MockDatabase db;
    Authentication auth(&db);

    EXPECT_CALL(db, userExists("Alice"))
        .WillOnce(Return(true));
    EXPECT_CALL(db, getPassword("Alice"))
        .WillOnce(Return("password"));

    EXPECT_TRUE(auth.login("Alice", "password"));
}

// Prueba para el inicio de sesión fallido
TEST(AuthenticationTest, LoginFailure) {
    MockDatabase db;
    Authentication auth(&db);

    EXPECT_CALL(db, userExists("Alice"))
        .WillOnce(Return(true));
    EXPECT_CALL(db, getPassword("Alice"))
        .WillOnce(Return("password"));

    EXPECT_FALSE(auth.login("Alice", "wrongpassword"));

    EXPECT_CALL(db, userExists("Bob"))
        .WillOnce(Return(false));

    EXPECT_FALSE(auth.login("Bob", "password"));
}

// Prueba para el registro de un nuevo usuario
TEST(AuthenticationTest, RegisterUser) {
    MockDatabase db;
    Authentication auth(&db);

    EXPECT_CALL(db, userExists("Charlie"))
        .WillOnce(Return(false));
    EXPECT_CALL(db, addUser("Charlie", "password"))
        .Times(1);

    auth.registerUser("Charlie", "password");
}

// Funcion principla para ejecutar los test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}