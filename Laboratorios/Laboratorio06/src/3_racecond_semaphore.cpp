#include <iostream>
#include <thread>
#include <vector>
#include <semaphore> // requiere C++20

using namespace std;

int counter = 0;
std::counting_semaphore<1> counterSem(1); // Semáforo binario

void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        counterSem.acquire();
        ++counter;
        counterSem.release();
    }
}

vector<int> myList;
std::counting_semaphore<1> listSem(1); // Otro semáforo binario para el vector

void addToList(int start) {
    for (int i = 0; i < 1000; ++i) {
        listSem.acquire();
        myList.push_back(start + i);
        listSem.release();
    }
}

int main() {
    vector<thread> threads;

    for (int i = 0; i < 10; ++i)
        threads.emplace_back(incrementCounter);

    for (auto &t : threads)
        t.join();

    cout << "Valor final del contador (esperado = 100000): " << counter << endl;

    vector<thread> vthreads;

    for (int i = 0; i < 10; ++i)
        vthreads.emplace_back(addToList, i * 1000);

    for (auto &t : vthreads)
        t.join();

    cout << "Tamaño final del vector (esperado = 10000): " << myList.size() << endl;

    return 0;
}
