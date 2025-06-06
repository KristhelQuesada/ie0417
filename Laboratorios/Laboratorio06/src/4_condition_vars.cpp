/*
 * DESCRIPCION
 * Este programa demuestra el uso de variables de condición (`condition_variable`)
 * para la sincronización entre hilos.
 * 
 * Un hilo (`waitingThread`) espera hasta que una condición (variable `ready`) se
 * vuelva verdadera, usando `cv.wait()` que libera el mutex y bloquea el hilo 
 * hasta que sea notificado.
 * 
 * Otro hilo (`notifyingThread`) simula trabajo (2 segundos) y luego cambia la
 * variable `ready` a true, notificando a través de `cv.notify_one()` para 
 * despertar al hilo en espera.
 * 
 * Este patrón es útil para coordinar tareas donde un hilo debe esperar hasta que
 * otro hilo le indique que puede continuar, evitando consumo activo de CPU.
 */


#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

// Mutex para proteger el acceso a la variable compartida "ready"
std::mutex mtx;

// Variable de condición para sincronizar los hilos
std::condition_variable cv;

// Variable que indica si la condición para continuar está lista
bool ready = false;

// Función que simula un hilo que espera hasta que "ready" sea true
void waitingThread() {
    std::unique_lock<std::mutex> lock(mtx); // Adquiere el mutex para proteger "ready"
    cout << "[Hilo] Esperando la señal..." << endl;

    // Espera bloqueante hasta que "ready" sea true.
    // La lambda es una condición que se evalúa cada vez que cv.notify_* es llamado.
    cv.wait(lock, []{ return ready; });

    // Aquí el hilo continua solo cuando "ready" es true
    cout << "[Hilo] Señal recibida, continuando ejecución..." << endl;
}

// Función que simula un hilo que después de un tiempo prepara la condición y notifica al hilo en espera
void notifyingThread() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simula trabajo o retardo

    {
        std::lock_guard<std::mutex> lock(mtx); // Bloquea el mutex para modificar "ready"
        ready = true;                          // Cambia la condición para desbloquear al hilo esperando
        cout << "[Notificador] Condición lista, notificando al hilo..." << endl;
    }

    cv.notify_one(); // Notifica a un solo hilo que esté esperando la variable de condición
}

int main() {
    // Crear un hilo que espera la condición
    thread t1(waitingThread);
    // Crear un hilo que después de un tiempo notificará la condición
    thread t2(notifyingThread);

    // Esperar a que ambos hilos terminen
    t1.join();
    t2.join();

    return 0;
}
