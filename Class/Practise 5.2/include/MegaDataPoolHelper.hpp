#pragma once

#include "MegaDataPool.hpp"
#include <memory>

std::shared_ptr<MegaData> acquireMegaData();
void releaseMegaData(std::shared_ptr<MegaData> data);
size_t getMegaDataPoolSize();
size_t getMegaDataPoolUsedSize();
