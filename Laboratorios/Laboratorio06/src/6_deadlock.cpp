#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

std::mutex mtx1, mtx2;

void threadA() {
    cout << "[Hilo A] Intentando bloquear mtx1..." << endl;
    std::lock_guard<std::mutex> lock1(mtx1);
    cout << "[Hilo A] Bloqueó mtx1" << endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    cout << "[Hilo A] Intentando bloquear mtx2..." << endl;
    std::lock_guard<std::mutex> lock2(mtx2);  // Aquí ocurre el deadlock
    cout << "[Hilo A] Bloqueó mtx2" << endl;
}

void threadB() {
    cout << "[Hilo B] Intentando bloquear mtx2..." << endl;
    std::lock_guard<std::mutex> lock1(mtx2);
    cout << "[Hilo B] Bloqueó mtx2" << endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    cout << "[Hilo B] Intentando bloquear mtx1..." << endl;
    std::lock_guard<std::mutex> lock2(mtx1);  // Aquí ocurre el deadlock
    cout << "[Hilo B] Bloqueó mtx1" << endl;
}

int main() {
    thread t1(threadA);
    thread t2(threadB);

    t1.join();
    t2.join();

    cout << "Fin del programa (no debería llegar aquí si hay deadlock)." << endl;
    return 0;
}
