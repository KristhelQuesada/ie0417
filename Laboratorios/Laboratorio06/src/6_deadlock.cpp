/*
 * DESCRIPCION
 * Este programa demuestra un caso clásico de deadlock entre dos hilos.
 * 
 * El hilo A bloquea primero el mutex mtx1 y luego intenta bloquear mtx2.
 * El hilo B bloquea primero el mutex mtx2 y luego intenta bloquear mtx1.
 * 
 * Como ambos hilos esperan que el otro libere el mutex que poseen, se produce
 * un interbloqueo (deadlock) y ninguno puede continuar.
 * 
 * El deadlock es un problema común en la programación concurrente cuando no se
 * controlan adecuadamente los recursos compartidos.
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;


// Dos mutex distintos que simulan recursos compartidos
std::mutex mtx1, mtx2;

// Función para el hilo A
void threadA() {
    cout << "[Hilo A] Intentando bloquear mtx1..." << endl;
    std::lock_guard<std::mutex> lock1(mtx1);  // Bloquea mtx1 primero
    cout << "[Hilo A] Bloqueó mtx1" << endl;

    // Simula trabajo, para dar tiempo a que otro hilo pueda bloquear el segundo mutex
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    cout << "[Hilo A] Intentando bloquear mtx2..." << endl;
    // Aquí intenta bloquear mtx2 mientras todavía tiene mtx1 bloqueado
    // Si otro hilo ya tiene mtx2 bloqueado y espera por mtx1, se produce un deadlock
    std::lock_guard<std::mutex> lock2(mtx2);
    cout << "[Hilo A] Bloqueó mtx2" << endl;
}

// Función para el hilo B
void threadB() {
    cout << "[Hilo B] Intentando bloquear mtx2..." << endl;
    std::lock_guard<std::mutex> lock1(mtx2);  // Bloquea mtx2 primero
    cout << "[Hilo B] Bloqueó mtx2" << endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    cout << "[Hilo B] Intentando bloquear mtx1..." << endl;
    // Intenta bloquear mtx1 mientras tiene mtx2 bloqueado
    // Si threadA tiene mtx1 bloqueado y espera por mtx2, ambos quedan bloqueados mutuamente
    std::lock_guard<std::mutex> lock2(mtx1);
    cout << "[Hilo B] Bloqueó mtx1" << endl;
}

int main() {
    // Crear dos hilos que intentan bloquear los mutex en orden inverso
    thread t1(threadA);
    thread t2(threadB);

    // Esperar a que ambos terminen (en deadlock, nunca se llega aquí)
    t1.join();
    t2.join();

    cout << "Fin del programa (no debería llegar aquí si hay deadlock)." << endl;
    return 0;
}
