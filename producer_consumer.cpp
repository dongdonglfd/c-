#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
std::queue<int> buffer;
const int MAX_BUFFER_SIZE = 10;

void producer() {
    int i = 0;
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));  // 模拟生产时间
        
        std::unique_lock<std::mutex> lock(mtx);
        if (buffer.size() == MAX_BUFFER_SIZE) {
            std::cout << "Buffer is full, producer is waiting..." << std::endl;
            cv.wait(lock, []() { return buffer.size() < MAX_BUFFER_SIZE; });  // 等待直到缓冲区有空间
        }

        buffer.push(i++);
        std::cout << "Produced: " << i << std::endl;
        cv.notify_all();  // 通知消费者可以消费了
    }
}

void consumer() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));  // 模拟消费时间
        
        std::unique_lock<std::mutex> lock(mtx);
        if (buffer.empty()) {
            std::cout << "Buffer is empty, consumer is waiting..." << std::endl;
            cv.wait(lock, []() { return !buffer.empty(); });  // 等待直到缓冲区有数据
        }

        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << item << std::endl;
        cv.notify_all();  // 通知生产者可以继续生产
    }
}

int main() {
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}
