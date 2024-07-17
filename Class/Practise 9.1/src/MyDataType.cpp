#include "MyDataType.hpp"

MyDataType::MyDataType() : value(int16_t(0)) {}

MyDataType::MyDataType(int16_t value) : value(value) {}

MyDataType::MyDataType(const std::string& value) : value(value) {}

MyDataType::MyDataType(const MapType& value) : value(value) {}

MyDataType::ValueType MyDataType::getValue() const {
    return value;
}