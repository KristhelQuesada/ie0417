/*
DESCRIPCION
Este programa introduce 
*/

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int counter = 0;

void incrementCounter() {
    for (int i = 0; i < 10000; ++i) {
        ++counter; // condición de carrera aquí
    }
}

vector<int> myList;

void addToList(int start) {
    for (int i = 0; i < 1000; ++i) {
        myList.push_back(start + i); // acceso concurrente sin protección
    }
}

int main() {
    vector<thread> threads;

    // Crear 10 hilos
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(incrementCounter);
    }

    for (auto &t : threads) {
        t.join();
    }

    cout << "Valor final del contador (esperado = 100000): " << counter << endl;

    vector<thread> vthreads;

    for (int i = 0; i < 10; ++i) {
        vthreads.emplace_back(addToList, i * 1000);
    }

    for (auto &t : vthreads) t.join();

    cout << "Tamaño final del vector (esperado = 10000): " << myList.size() << endl;

    return 0;
}

