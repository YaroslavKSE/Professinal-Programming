#pragma once

#include "MyDataType.hpp"
#include <vector>
#include <string>
#include <fstream>

class MsgPackSerializer {
public:
    static std::vector<uint8_t> serialize(const MyDataType& data);
    static void saveToFile(const std::string& filename, const MyDataType& data);

private:
    static void serializeInt16(std::vector<uint8_t>& buffer, int16_t value);
    static void serializeString(std::vector<uint8_t>& buffer, const std::string& value);
    static void serializeMap(std::vector<uint8_t>& buffer, const MyDataType::MapType& value);
};