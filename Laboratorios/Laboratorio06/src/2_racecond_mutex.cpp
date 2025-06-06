/*
 * DESCRIPCION
 * Este programa demuestra cómo resolver condiciones de carrera usando `std::mutex`.
 * 
 * Se reutiliza la estructura del ejemplo anterior, pero ahora se emplean mutexes para 
 * proteger el acceso a recursos compartidos:
 * 
 * 1. El contador global `counter` es incrementado por 10 hilos, cada uno utilizando
 *    `lock_guard` para asegurar acceso exclusivo.
 * 
 * 2. El vector `myList` también es modificado por múltiples hilos, pero cada inserción 
 *    está protegida por un mutex para evitar corrupción o acceso concurrente.
 * 
 * Este ejemplo ilustra cómo los mutexes garantizan consistencia en los resultados
 * y eliminan errores de sincronización que surgen al trabajar con múltiples hilos.
 */


#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;


// Variables globales
int counter = 0;        // Variable global compartida protegida con mutex
mutex counterMutex;     // Mutex para proteger el acceso a 'counter'

// Función que incrementa el contador 10,000 veces
// Usa lock_guard para asegurar acceso exclusivo al contador en cada incremento
void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        // Al crear lock_guard se bloquea el mutex automáticamente
        lock_guard<mutex> lock(counterMutex);
        ++counter;  // Se evita la condición de carrera con esta protección
    }
}

// Variables globales, ejempplo con vector
vector<int> myList;     // Vector global compartido protegido con mutex
mutex listMutex;        // Mutex para proteger el acceso al vector

// Función que añade 1000 elementos al vector de manera segura
void addToList(int start) {
    for (int i = 0; i < 1000; ++i) {
        // Protege el acceso concurrente a myList
        lock_guard<mutex> lock(listMutex);
        myList.push_back(start + i);  // Operación segura concurrentemente
    }
}

int main() {
    vector<thread> threads;

    // Crear 10 hilos que incrementan el contador simultáneamente
    // Gracias al mutex, el acceso concurrente está sincronizado
    for (int i = 0; i < 10; ++i)
        threads.emplace_back(incrementCounter);

    // Esperar que todos los hilos terminen su trabajo
    for (auto &t : threads)
        t.join();

    // Ahora el valor debe ser el esperado: 10 * 10000 = 100000
    cout << "Valor final del contador (esperado = 100000): " << counter << endl;

    vector<thread> vthreads;

    // Crear 10 hilos que añaden elementos al vector simultáneamente
    // Mutex evita corrupción por acceso concurrente
    for (int i = 0; i < 10; ++i)
        vthreads.emplace_back(addToList, i * 1000);

    // Esperar que terminen todos los hilos
    for (auto &t : vthreads)
        t.join();

    // Tamaño esperado: 10 * 1000 = 10000 elementos
    cout << "Tamaño final del vector (esperado = 10000): " << myList.size() << endl;

    return 0;
}