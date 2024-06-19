#include "MegaDataPool.hpp"
#include <stdexcept>
#include <algorithm>

MegaDataPool::MegaDataPool(size_t poolSize)
    : poolSize(poolSize), pool(poolSize), used(poolSize, false) {
    for (size_t i = 0; i < poolSize; ++i) {
        pool[i] = std::make_shared<MegaData>();
    }
}

std::shared_ptr<MegaData> MegaDataPool::acquire() {
    std::lock_guard<std::mutex> lock(poolMutex);
    for (size_t i = 0; i < poolSize; ++i) {
        if (!used[i]) {
            used[i] = true;
            auto ptr = pool[i];
            return std::shared_ptr<MegaData>(ptr.get(), [this, i](MegaData* ptr) { release(i); });
        }
    }
    throw std::runtime_error("No available objects in the pool");
}

void MegaDataPool::release(size_t index) {
    std::lock_guard<std::mutex> lock(poolMutex);
    if (index >= poolSize) {
        throw std::out_of_range("Invalid index for release");
    }
    used[index] = false;
    pool[index]->reset();
}

size_t MegaDataPool::size() const {
    return poolSize;
}

size_t MegaDataPool::usedSize() const {
    std::lock_guard<std::mutex> lock(poolMutex);
    return std::count_if(used.begin(), used.end(), [](bool flag) { return flag; });
}

void MegaDataPool::resetAll() {
    std::lock_guard<std::mutex> lock(poolMutex);
    for (auto& data : pool) {
        data->reset();
    }
}
