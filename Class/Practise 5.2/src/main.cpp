#include "MegaDataPoolHelper.hpp"
#include <print>
#include <iostream>
#include <thread>
#include <vector>
#include "Config.hpp"

void testPool() {
    try {
        auto data = acquireMegaData();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::println("Thread acquired MegaData, used size: {}", getMegaDataPoolUsedSize());
        releaseMegaData(data);
        std::println("Thread released MegaData, used size: {}", getMegaDataPoolUsedSize());
    } catch (const std::runtime_error& e) {
        std::println("Exception in thread: {}", e.what()); // Will print the error when no available objects in the pool
    }
}

int main() {
    try {
        size_t poolSize = Constants::defaultPoolSize;  
        MegaDataPool::getInstance(poolSize); 

        std::vector<std::thread> threads;
        // Number of threads > pool size
        for (int i = 0; i < Constants::numThreads; ++i) {
            threads.emplace_back(testPool);
        }

        for (auto& thread : threads) {
            thread.join();
        }

        std::println("Final pool used size: {}", getMegaDataPoolUsedSize());
    } catch (const std::exception& e) {
        std::println("Unhandled exception: {}", e.what());
    }

    return 0;
}
