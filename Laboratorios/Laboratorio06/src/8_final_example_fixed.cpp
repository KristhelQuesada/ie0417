/*
 * DESCRIPCION
 * Este programa resuelve el problema productor-consumidor con múltiples productores y consumidores
 * usando un buffer limitado y mecanismos de sincronización en C++20.
 *
 * Usa un buffer compartido protegido por mutex, semáforos para controlar espacios vacíos y llenos,
 * y variables de condición para la notificación entre hilos.
 *
 * Los productores generan elementos y los insertan en el buffer solo si hay espacio disponible.
 * Los consumidores extraen elementos solo si el buffer contiene datos.
 *
 * Además, implementa una señal de parada (STOP_SIGNAL) para indicar a los consumidores cuándo finalizar,
 * permitiendo una terminación ordenada de todos los hilos consumidores tras que los productores terminan.
 *
 * Esto asegura acceso seguro y sincronizado al buffer evitando condiciones de carrera,
 * bloqueos o accesos concurrentes indebidos.
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <semaphore>

constexpr int BUFFER_SIZE = 5;                      // Tamaño máximo del buffer compartido
std::queue<int> buffer;                             // Buffer FIFO para almacenar ítems producidos
std::mutex mtx;                                     // Mutex para proteger acceso al buffer
std::condition_variable cv_producer, cv_consumer;   // Variables de condición para sincronizar productores y consumidores
std::counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE); // Slots vacíos inicialmente llenos
std::counting_semaphore<BUFFER_SIZE> full_slots(0);            // Slots llenos inicialmente 0

const int STOP_SIGNAL = -1; // Señal para detener a los consumidores

// Función para productor
void producer(int id, int num_tasks) {
    for (int i = 0; i < num_tasks; ++i) {
        int item = id * 100 + i;

        empty_slots.acquire();  // Esperar slot vacío disponible
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(item);
            std::cout << "Producer: " << id << " produced item " << item << std::endl;
        }
        full_slots.release();   // Indicar nuevo ítem disponible
        cv_consumer.notify_one(); // Notificar a consumidor
    }
}

// Función para consumidor
void consumer(int id) {
    while (true) {
        full_slots.acquire();   // Esperar ítem disponible
        std::unique_lock<std::mutex> lock(mtx);
        cv_consumer.wait(lock, [] { return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();

        if (item == STOP_SIGNAL) {
            std::cout << "Consumer " << id << " received stop signal." << std::endl;
            break; // Termina el hilo consumidor
        }

        std::cout << "Consumer " << id << " consumed item " << item << std::endl;

        lock.unlock();
        empty_slots.release();    // Indicar slot vacío disponible
        cv_producer.notify_one(); // Notificar a productor

        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Simular procesamiento
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

    // Esperar que terminen los productores
    for (auto& producer_thread : producers) {
        producer_thread.join();
    }

    // Enviar señal de parada para cada consumidor
    for (int i = 0; i < num_consumers; ++i) {
        empty_slots.acquire(); // Esperar espacio en buffer
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(STOP_SIGNAL);
        }
        full_slots.release();      // Indicar nuevo ítem
        cv_consumer.notify_one();  // Notificar consumidor
    }

    // Esperar que terminen los consumidores
    for (auto& consumer_thread : consumers) {
        consumer_thread.join();
    }

    std::cout << "All consumers have finished." << std::endl;

    return 0;
}
