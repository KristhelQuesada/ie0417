/*
 * DESCRIPCION
 * Este programa implementa el clásico problema productor-consumidor con un buffer
 * limitado usando múltiples productores y consumidores.
 *
 * Se usa un buffer compartido (cola) protegido por un mutex, semáforos para controlar
 * el número de espacios vacíos y llenos, y variables de condición para notificar a los hilos.
 *
 * Los productores generan elementos y los agregan al buffer solo cuando hay espacio disponible,
 * y los consumidores extraen elementos solo cuando hay elementos disponibles.
 *
 * Este ejemplo demuestra sincronización efectiva entre hilos para evitar condiciones de carrera
 * y acceso concurrente incorrecto al buffer.
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <semaphore>

constexpr int BUFFER_SIZE = 5; // Tamaño máximo del buffer compartido
std::queue<int> buffer;        // Buffer FIFO para almacenar ítems producidos

std::mutex mtx;                // Mutex para proteger acceso al buffer
std::condition_variable cv_producer, cv_consumer; // Variables de condición para sincronizar productores y consumidores

// Semáforo para contar slots vacíos disponibles en el buffer (inicia en BUFFER_SIZE)
std::counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE);

// Semáforo para contar slots llenos disponibles en el buffer (inicia en 0)
std::counting_semaphore<BUFFER_SIZE> full_slots(0);

// Función que simula a un productor
void producer(int id, int num_tasks) {
    for (int i = 0; i < num_tasks; ++i) {
        int item = id * 100 + i; // Crea un ítem (dummy, para identificación)

        empty_slots.acquire();   // Espera a que haya espacio en el buffer (slot vacío disponible)

        {
            // Sección crítica protegida para acceso seguro al buffer
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(item);   // Inserta ítem en buffer
            std::cout << "Producer: " << id << " produced item " << item << std::endl;
        }

        full_slots.release();    // Señala que hay un nuevo ítem disponible (slot lleno)
        cv_consumer.notify_one(); // Notifica a un consumidor que puede consumir
    }
}

// Función que simula a un consumidor
void consumer(int id) {
    while (true) {
        full_slots.acquire();   // Espera a que haya ítems para consumir (slot lleno disponible)

        std::unique_lock<std::mutex> lock(mtx);
        // Espera en la variable de condición hasta que buffer no esté vacío
        cv_consumer.wait(lock, [] { return !buffer.empty(); });

        int item = buffer.front(); // Obtiene el ítem del frente del buffer
        buffer.pop();              // Elimina ítem consumido del buffer
        std::cout << "Consumer " << id << " consumed item " << item << std::endl;

        lock.unlock();

        empty_slots.release();     // Señala que hay un nuevo slot vacío en el buffer
        cv_producer.notify_one();  // Notifica a un productor que puede producir

        // Simula tiempo de procesamiento del ítem
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    const int num_producers = 2;
    const int num_consumers = 3;
    const int num_tasks_per_producer = 10;

    std::vector<std::thread> producers, consumers;

    // Crear hilos productores
    for (int i = 0; i < num_producers; ++i) {
        producers.emplace_back(producer, i, num_tasks_per_producer);
    }

    // Crear hilos consumidores
    for (int i = 0; i < num_consumers; ++i) {
        consumers.emplace_back(consumer, i);
    }

    // Esperar que todos los productores terminen de producir
    for (auto& producer_thread : producers) {
        producer_thread.join();
    }

    // Esperar un tiempo para que consumidores terminen de procesar los ítems
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Nota: Aquí los consumidores no se terminan de forma controlada, solo el programa finaliza
    std::cout << "All producers have finished." << std::endl;

    return 0;
}
