cmake_minimum_required(VERSION 3.10)
project(CalculatorTest)

# Agregar Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)


# --------- TEST 1: Calculator Unit Test ---------
# Agregar el ejecutable y los test
add_executable(test_calculator 2_test_calculator.cpp)
target_link_libraries(test_calculator gtest_main)
add_test(NAME test_calculator COMMAND test_calculator)

# --------- TEST 2: Authentication with GoogleMock ---------
add_executable(test_authentication
    3_test_authentication.cpp
    3_authentication.h
    3_database.h
    3_mock_database.h
)
target_link_libraries(test_authentication gtest gmock gtest_main)
add_test(NAME test_authentication COMMAND test_authentication)

enable_testing()
