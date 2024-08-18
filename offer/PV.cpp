#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int count = 0;

void producer() {
    std::unique_lock<std::mutex> lock(mtx);
    // 生产资源
    ++count;
    std::cout << "Produced, count = " << count << std::endl;
    cv.notify_one(); // 通知等待的消费者线程
}

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    while (count == 0) {
        cv.wait(lock); // 等待资源可用
    }
    // 消费资源
    --count;
    std::cout << "Consumed, count = " << count << std::endl;
}

int main() {
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}
