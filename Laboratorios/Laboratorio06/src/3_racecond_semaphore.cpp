/*
 * DESCRIPCION
 * Este programa demuestra el uso de semáforos binarios (`counting_semaphore<1>`)
 * como mecanismo de sincronización para prevenir condiciones de carrera.
 * 
 * En lugar de `mutex`, se utiliza un semáforo con capacidad 1 para simular 
 * exclusión mutua:
 * 
 * 1. El contador `counter` es protegido mediante `counterSem.acquire()` y 
 *    `counterSem.release()` en cada incremento por parte de múltiples hilos.
 * 
 * 2. El vector `myList` también es compartido entre hilos, y su acceso es 
 *    controlado por `listSem`.
 * 
 * Este ejemplo ilustra cómo los semáforos pueden actuar como locks para
 * secciones críticas, siendo una alternativa válida a los mutexes cuando 
 * se desea un control más explícito de la disponibilidad del recurso.
 */

#include <iostream>
#include <thread>
#include <vector>
#include <semaphore> // requiere C++20

using namespace std;

// Variable global compartida
int counter = 0;
// Semáforo binario para proteger el acceso al contador
// Inicializado con 1 para permitir el acceso a un solo hilo a la vez
std::counting_semaphore<1> counterSem(1);

// Función que incrementa el contador 10,000 veces
// Utiliza el semáforo para evitar condiciones de carrera
void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        counterSem.acquire(); // Espera (decrementa) el semáforo para entrar a la sección crítica
        ++counter;            // Sección crítica protegida: acceso exclusivo al contador
        counterSem.release(); // Libera (incrementa) el semáforo permitiendo que otro hilo acceda
    }
}

// Vector global compartido
vector<int> myList;
// Semáforo binario para proteger el acceso concurrente al vector
std::counting_semaphore<1> listSem(1);

// Función que añade 1000 elementos al vector de forma segura
void addToList(int start) {
    for (int i = 0; i < 1000; ++i) {
        listSem.acquire();           // Bloquea el semáforo para proteger la sección crítica
        myList.push_back(start + i); // Sección crítica protegida: acceso exclusivo al vector
        listSem.release();           // Libera el semáforo para otros hilos
    }
}

int main() {
    vector<thread> threads;

    // Crear 10 hilos que incrementan el contador simultáneamente
    // El semáforo binario garantiza acceso mutuo excluyente
    for (int i = 0; i < 10; ++i)
        threads.emplace_back(incrementCounter);

    // Esperar a que todos los hilos terminen
    for (auto &t : threads)
        t.join();

    // El valor esperado del contador es 10 * 10000 = 100000
    cout << "Valor final del contador (esperado = 100000): " << counter << endl;

    vector<thread> vthreads;

    // Crear 10 hilos que añaden elementos al vector simultáneamente
    // Semáforo binario protege el vector de accesos concurrentes
    for (int i = 0; i < 10; ++i)
        vthreads.emplace_back(addToList, i * 1000);

    // Esperar a que terminen todos los hilos
    for (auto &t : vthreads)
        t.join();

    // Tamaño esperado: 10 * 1000 = 10000 elementos en total
    cout << "Tamaño final del vector (esperado = 10000): " << myList.size() << endl;

    return 0;
}