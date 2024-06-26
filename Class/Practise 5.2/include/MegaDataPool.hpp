#pragma once

#include <vector>
#include <memory>
#include <mutex>
#include "MegaData.hpp"

class MegaDataPool {
public:
    static MegaDataPool& getInstance(size_t poolSize = 10) {
        static MegaDataPool instance(poolSize);
        return instance;
    }

    [[nodiscard]] std::shared_ptr<MegaData> acquire();
    void release(size_t index);

    [[nodiscard]] size_t size() const;
    [[nodiscard]] size_t usedSize() const;

    MegaDataPool(const MegaDataPool&) = delete;
    MegaDataPool& operator=(const MegaDataPool&) = delete;

private:
    MegaDataPool(size_t poolSize);

    size_t poolSize;
    std::vector<std::shared_ptr<MegaData>> pool;
    std::vector<bool> used;
    mutable std::mutex poolMutex;

    void resetAll();
};
