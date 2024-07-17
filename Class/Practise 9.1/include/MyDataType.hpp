#pragma once

#include <string>
#include <vector>
#include <variant>
#include <cstdint>

class MyDataType {
public:
    using MapType = std::vector<std::pair<std::string, MyDataType>>;
    using ValueType = std::variant<int16_t, std::string, MapType>;

    MyDataType();
    explicit MyDataType(int16_t value);
    explicit MyDataType(const std::string& value);
    explicit MyDataType(const MapType& value);

    ValueType getValue() const;

private:
    ValueType value;
};