/*
 * DESCRIPCION
 * Este programa ilustra el uso de una barrera (`std::barrier`) para sincronizar 
 * un grupo de hilos.
 * 
 * Se crea una barrera para 5 hilos que hace que cada hilo espere hasta que todos 
 * hayan llegado al punto de sincronización (`arrive_and_wait()`).
 * 
 * Cada hilo realiza un trabajo simulado con retraso variable antes de llegar a 
 * la barrera. Una vez que todos los hilos llegan, se desbloquean simultáneamente 
 * y continúan su ejecución.
 * 
 * Las barreras son útiles para coordinar fases en paralelismo donde todos los 
 * hilos deben completar una etapa antes de avanzar a la siguiente.
 */

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <barrier>          // C++20: para sincronización de hilos con barreras

using namespace std;

// Definimos una barrera para 5 hilos.
// La barrera bloquea la ejecución de cada hilo en el punto sync_point.arrive_and_wait()
// hasta que los 5 hilos hayan llegado, entonces todos continúan simultáneamente.
// No se define función adicional a ejecutar cuando la barrera se completa (acción vacía).
std::barrier sync_point(5);

void threadFunction(int id) {
    cout << "[Hilo " << id << "] trabajando antes de la barrera...\n";

    // Simula trabajo haciendo que cada hilo duerma diferente tiempo,
    // para que lleguen en diferentes momentos a la barrera.
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));

    cout << "[Hilo " << id << "] esperando en la barrera...\n";

    // Punto de sincronización: el hilo se bloquea aquí
    // hasta que todos los hilos hayan llamado arrive_and_wait().
    sync_point.arrive_and_wait();

    // Cuando los 5 hilos han llegado, todos se desbloquean y continúan juntos.
    cout << "[Hilo " << id << "] continuando después de la barrera.\n";
}

int main() {
    vector<thread> threads;

    // Crear 5 hilos, cada uno ejecuta threadFunction con un ID distinto
    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(threadFunction, i);
    }

    // Esperar que todos los hilos terminen para evitar finalización prematura
    for (auto& t : threads) t.join();

    return 0;
}
