#include "MegaDataPoolHelper.hpp"

std::shared_ptr<MegaData> acquireMegaData() {
    return MegaDataPool::getInstance().acquire();
}

void releaseMegaData(std::shared_ptr<MegaData> data) {
    // The shared_ptr will call the custom deleter and release the object back to the pool
    data.reset();
}

size_t getMegaDataPoolSize() {
    return MegaDataPool::getInstance().size();
}

size_t getMegaDataPoolUsedSize() {
    return MegaDataPool::getInstance().usedSize();
}
