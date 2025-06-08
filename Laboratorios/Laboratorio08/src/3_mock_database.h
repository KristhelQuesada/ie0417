#ifndef MOCK_DATABASE_H
#define MOCK_DATABASE_H

#include <gmock/gmock.h>
#include "3_database.h"

// Engañamos al sistema simulando que estamos usando una base de datos real,
// pero en realidad usamos métodos mock que se comportan igual que los reales.
// Esto nos permite probar la lógica de autenticación sin necesidad de tener
// una base de datos implementada, ya que el mock hereda la estructura original
// y nos deja controlar su comportamiento durante las pruebas.


class MockDatabase : public Database {
    public:
        MOCK_METHOD(bool, userExists, (const std::string& username), (override));
        MOCK_METHOD(std::string, getPassword, (const std::string& username), (override));
        MOCK_METHOD(void, addUser, (const std::string& username, const std::string& password), (override));
};

#endif //MOCK_DATABASE_H