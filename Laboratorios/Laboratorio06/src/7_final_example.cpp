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

void consumer(int id) {
    while (true) {
        full_slots.acquire();       // decrementa el contador de slots llenos
        std::unique_lock<std::mutex> lock(mtx);

        // Espera hasta que haya un item en el buffer
        cv_consumer.wait(lock, [] { return !buffer.empty(); });

        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumer " << id << " consumed items " << item << std::endl;
        
        lock.unlock();
        empty_slots.release();          // incrementa el contador de slots vacios
        cv_producer.notify_one();       // NOfifica a un productor

        // SImulate processing time
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

    // Allow coosumers to finish processing
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // Ideally we would signal consumers to stop but for simplicity we just exit
    std::cout << "All producers have finished." << std::endl;

    return 0;
}
