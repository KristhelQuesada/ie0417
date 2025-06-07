#ifndef MOCK_DATABASE_H
#define MOCK_DATABASE_H

#include <gmock/gmock.h>
#include "3_database.h"

// Engañamos al sistema, haciendo pasar la base de datos real
// por mock methods, que heredan las funciones del esquema real
// de la db

class MockDatabase : public Database {
    public:
        MOCK_METHOD(bool, userExists, (const std::string& username), (override));
        MOCK_METHOD(std::string, getPassword, (const std::string& username), (override));
        MOCK_METHOD(void, addUser, (const std::string& username, const std::string& password), (override));
};

#endif //MOCK_DATABASE_H