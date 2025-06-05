#include <iostream>
#include <thread>
#include <barrier>
#include <vector>
#include <chrono>

using namespace std;

// Barrera para 5 hilos, sin acción al completarse
std::barrier sync_point(5);

void threadFunction(int id) {
    cout << "[Hilo " << id << "] trabajando antes de la barrera...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));

    cout << "[Hilo " << id << "] esperando en la barrera...\n";
    sync_point.arrive_and_wait();

    cout << "[Hilo " << id << "] continuando después de la barrera.\n";
}

int main() {
    vector<thread> threads;

    for (int i = 0; i < 5; ++i) {
        threads.emplace_back(threadFunction, i);
    }

    for (auto& t : threads) t.join();

    return 0;
}
