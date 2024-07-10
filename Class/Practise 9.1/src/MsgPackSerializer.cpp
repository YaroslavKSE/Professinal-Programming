#include "MsgPackSerializer.hpp"
#include <stdexcept>
#include <format>

std::vector<uint8_t> MsgPackSerializer::serialize(const MyDataType& data) {
    std::vector<uint8_t> buffer;
    
    std::visit([&buffer](const auto& value) {
        using T = std::decay_t<decltype(value)>;
        if constexpr (std::is_same_v<T, int16_t>) {
            serializeInt16(buffer, value);
        } else if constexpr (std::is_same_v<T, std::string>) {
            serializeString(buffer, value);
        } else if constexpr (std::is_same_v<T, MyDataType::MapType>) {
            serializeMap(buffer, value);
        }
    }, data.getValue());

    return buffer;
}

void MsgPackSerializer::saveToFile(const std::string& filename, const MyDataType& data) {
    std::vector<uint8_t> serialized = serialize(data);
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error(std::format("Unable to open file: {}", filename));
    }
    file.write(reinterpret_cast<const char*>(serialized.data()), serialized.size());
}

void MsgPackSerializer::serializeInt16(std::vector<uint8_t>& buffer, int16_t value) {
    buffer.push_back(0xd1);  // int16
    buffer.push_back(static_cast<uint8_t>((value >> 8) & 0xFF));
    buffer.push_back(static_cast<uint8_t>(value & 0xFF));
}

void MsgPackSerializer::serializeString(std::vector<uint8_t>& buffer, const std::string& value) {
    if (value.length() > 30) {
        throw std::runtime_error("String length exceeds 30 characters");
    }
    
    if (value.length() < 32) {
        buffer.push_back(static_cast<uint8_t>(0xa0 | value.length()));
    } else {
        buffer.push_back(0xd9);  // str8
        buffer.push_back(static_cast<uint8_t>(value.length()));
    }
    
    buffer.insert(buffer.end(), value.begin(), value.end());
}

void MsgPackSerializer::serializeMap(std::vector<uint8_t>& buffer, const MyDataType::MapType& value) {
    if (value.size() > 15) {
        throw std::runtime_error("Map size exceeds 15 elements");
    }
    
    buffer.push_back(static_cast<uint8_t>(0x80 | value.size()));
    
    for (const auto& [key, val] : value) {
        serializeString(buffer, key);
        std::vector<uint8_t> serializedValue = serialize(val);
        buffer.insert(buffer.end(), serializedValue.begin(), serializedValue.end());
    }
}