#include "MyDataType.hpp"
#include "MsgPackSerializer.hpp"
#include <format>
#include <print>

int main() {
    // Example usage
    MyDataType intData(42);
    MyDataType stringData("Hello, MsgPack!");
    MyDataType::MapType mapData = {
        {"key1", MyDataType(123)},
        {"key2", MyDataType("nested string")},
    };
    MyDataType mapDataType(mapData);

    std::println("Serializing int data:");
    auto serializedInt = MsgPackSerializer::serialize(intData);
    for (uint8_t byte : serializedInt) {
        std::print("{:02x} ", byte);
    }
    std::println("");

    std::println("Serializing string data:");
    auto serializedString = MsgPackSerializer::serialize(stringData);
    for (uint8_t byte : serializedString) {
        std::print("{:02x} ", byte);
    }
    std::println("");

    std::println("Serializing map data:");
    auto serializedMap = MsgPackSerializer::serialize(mapDataType);
    for (uint8_t byte : serializedMap) {
        std::print("{:02x} ", byte);
    }
    std::println("");

    // Save to file
    MsgPackSerializer::saveToFile("output.msgpack", mapDataType);
    std::println("Serialized data saved to output.msgpack");

    return 0;
}