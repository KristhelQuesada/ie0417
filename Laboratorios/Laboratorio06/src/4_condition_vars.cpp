#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

std::mutex mtx;
std::condition_variable cv;

bool ready = false;

void waitingThread() {
    std::unique_lock<std::mutex> lock(mtx);
    cout << "[Hilo] Esperando la señal..." << endl;
    cv.wait(lock, []{ return ready; });  // Bloquea hasta que ready == true
    cout << "[Hilo] Señal recibida, continuando ejecución..." << endl;
}

void notifyingThread() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simula trabajo
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
        cout << "[Notificador] Condición lista, notificando al hilo..." << endl;
    }
    cv.notify_one();  // Notifica al hilo en espera
}

int main() {
    thread t1(waitingThread);
    thread t2(notifyingThread);

    t1.join();
    t2.join();

    return 0;
}
