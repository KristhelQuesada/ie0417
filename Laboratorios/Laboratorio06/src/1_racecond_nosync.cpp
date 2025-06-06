/*
 * DESCRIPCION
 * Este programa introduce el concepto de condiciones de carrera (race conditions)
 * cuando se usan múltiples hilos que acceden y modifican datos compartidos sin
 * ningún mecanismo de sincronización. 
 * 
 * Dos ejemplos son mostrados:
 * 
 * 1. Un contador global (`counter`) es incrementado por 10 hilos simultáneamente.
 *    Al no usar mutexes, el valor final suele ser menor al esperado debido a escrituras concurrentes.
 * 
 * 2. Un vector (`myList`) es modificado por múltiples hilos que agregan elementos.
 *    Al no proteger el acceso con mecanismos como mutexes, esto puede resultar en corrupción de datos
 *    o tamaños inconsistentes del vector.
 * 
 * Este código sirve como base para comparar el comportamiento sin sincronización
 * frente a soluciones con mutexes, semáforos y otras primitivas.
*/

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// Variable global compartida sin protección
int counter = 0;

// Función que incrementa el contador 10,000 veces
// ¡Atención! Aquí ocurre una condición de carrera al modificar 'counter' desde varios hilos simultáneamente
void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        ++counter; // Acceso concurrente no sincronizado -> condición de carrera
    }
}

// Vector global compartido sin protección
vector<int> myList;

// Función que añade elementos al vector
// Acceso concurrente sin protección puede causar comportamiento indefinido o corrupción de datos
void addToList(int start) {
    for (int i = 0; i < 1000; ++i) {
        myList.push_back(start + i); // Modificación concurrente no sincronizada -> riesgo de corrupción
    }
}

int main() {
    vector<thread> threads;

    // Crear 10 hilos que ejecutan incrementCounter simultáneamente
    // Esto provoca condición de carrera en la variable 'counter'
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(incrementCounter);
    }

    // Esperar que todos los hilos terminen
    for (auto &t : threads) {
        t.join();
    }

    // Valor esperado: 10000 incrementos por 10 hilos = 100000
    // Probablemente el valor impreso sea menor debido a condición de carrera
    cout << "Valor final del contador (esperado = 100000): " << counter << endl;

    vector<thread> vthreads;

    // Crear 10 hilos que ejecutan addToList simultáneamente
    // Sin sincronización, modificar el vector concurrentemente es inseguro
    for (int i = 0; i < 10; ++i) {
        vthreads.emplace_back(addToList, i * 1000);
    }

    // Esperar a que terminen todos los hilos
    for (auto &t : vthreads) t.join();

    // Tamaño esperado: 10 hilos * 1000 elementos = 10000
    // El resultado puede ser incorrecto o el programa puede tener comportamiento indefinido
    cout << "Tamaño final del vector (esperado = 10000): " << myList.size() << endl;

    return 0;
}

