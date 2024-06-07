#include "MegaData.hpp"

MegaData::MegaData() {
    reset();
}

void MegaData::reset() {
    smallArray.fill(42.0f);
    bigArray.fill(42.0);
}
