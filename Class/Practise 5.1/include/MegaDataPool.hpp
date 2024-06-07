#pragma once

#include <vector>
#include <memory>
#include "MegaData.hpp"

class MegaDataPool {
public:
    explicit MegaDataPool(size_t poolSize);

    [[nodiscard]] std::shared_ptr<MegaData> acquire();
    void release(size_t index);

    [[nodiscard]] size_t size() const;
    [[nodiscard]] size_t usedSize() const;

private:
    size_t poolSize;
    std::vector<std::shared_ptr<MegaData>> pool;
    std::vector<bool> used;
};