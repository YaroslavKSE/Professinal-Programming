#include <iostream>
#include <print>
#include "MegaDataPool.hpp"

int main() {
    try {
        MegaDataPool pool(10);

        auto data1 = pool.acquire();
        auto data2 = pool.acquire();

        std::println("Pool size: {}", pool.size());
        std::println("Used size: {}", pool.usedSize());

        // Release one object back to the pool
        data1.reset();

        std::println("Used size after release: {}", pool.usedSize());

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
