#include "MegaDataPool.hpp"
#include <iostream>
#include <print>

int main() {
    MegaDataPool pool(5);

    auto data1 = pool.acquire();
    auto data2 = pool.acquire();

    std::println("Pool size: {}", pool.size());
    std::println("Used size: {}", pool.usedSize());

    data1.reset();  // Release data1 back to the pool

    std::println("Used size after release: {}", pool.usedSize());

    try {
        auto data3 = pool.acquire();
        auto data4 = pool.acquire();
        auto data5 = pool.acquire();
        auto data6 = pool.acquire(); 
        auto data7 = pool.acquire(); // This will throw an exception
    } catch (const std::runtime_error& e) {
        std::println("Exception: {}", e.what());
    }

    return 0;
}
