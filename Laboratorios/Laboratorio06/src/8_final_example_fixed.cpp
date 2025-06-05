#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <semaphore>

constexpr int BUFFER_SIZE = 5;
std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv_producer, cv_consumer;
std::counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE); // Inicializando con BUFFER_SIZE
std::counting_semaphore<BUFFER_SIZE> full_slots(0);            // Inicializando con 0

void producer(int id, int num_tasks) {
    for (int i = 0; i < num_tasks; ++i) {
        // Produce an item (this is just a dummy item)
        int item = id * 100 + i;
        empty_slots.acquire();      // Decrementa el contador de slots vacios

        // Critical section
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(item);
            std::cout << "Producer: " << id << " produced item " << item << std::endl;
        }

        full_slots.release();       // Incrementa el contador de slots llenos
        cv_consumer.notify_one();   // Notifica a un consumidor
    }
}

int const STOP_SIGNAL = -1;

void consumer(int id) {
    while (true) {
        full_slots.acquire();
        std::unique_lock<std::mutex> lock(mtx);
        cv_consumer.wait(lock, [] { return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();

        if (item == STOP_SIGNAL) {
            std::cout << "Consumer " << id << " received stop signal." << std::endl;
            break;  // Sal del bucle
        }

        std::cout << "Consumer " << id << " consumed item " << item << std::endl;
        lock.unlock();
        empty_slots.release();
        cv_producer.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}


int main() {
    const int num_producers = 2;
    const int num_consumers = 3;
    const int num_tasks_per_producer = 10;

    std::vector<std::thread> producers, consumers;

    // CReate prodiucer threads
    for (int i = 0; i < num_producers; ++i) {
        producers.emplace_back(producer, i, num_tasks_per_producer);
    }

    // CReate consumer threads
    for (int i = 0; i < num_consumers; ++i) {
        consumers.emplace_back(consumer, i);
    }

    // JOin producer threads
    for (auto& producer_thread : producers) {
        producer_thread.join();
    }

    // Enviar señal de parada a cada consumidor
    for (int i = 0; i < num_consumers; ++i) {
        empty_slots.acquire(); // Espera hasta que haya espacio en el buffer
        {
            std::lock_guard<std::mutex> lock(mtx);
            buffer.push(STOP_SIGNAL);
        }
        full_slots.release();      // Indica que hay un nuevo elemento
        cv_consumer.notify_one();  // Notifica al consumidor
    }

    // Esperar a que terminen los consumidores
    for (auto& consumer_thread : consumers) {
        consumer_thread.join();
    }

    std::cout << "All consumers have finished." << std::endl;
    
    return 0;
}
