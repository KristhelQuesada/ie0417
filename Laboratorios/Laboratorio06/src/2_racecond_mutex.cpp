#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

int counter = 0;
mutex counterMutex;

void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        lock_guard<mutex> lock(counterMutex);
        ++counter;
    }
}

vector<int> myList;
mutex listMutex;

void addToList(int start) {
    for (int i = 0; i < 1000; ++i) {
        lock_guard<mutex> lock(listMutex);
        myList.push_back(start + i);
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
