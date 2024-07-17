import Foundation

class MsgPackSerializer {
    
    static func serialize(_ data: MyDataType) -> [UInt8] {
        var buffer: [UInt8] = []
        
        switch data.getValue() {
        case .int16(let value):
            serializeInt16(&buffer, value)
        case .string(let value):
            serializeString(&buffer, value)
        case .map(let value):
            serializeMap(&buffer, value)
        }
        
        return buffer
    }
    
    static func deserialize(_ data: [UInt8]) -> MyDataType {
        var index = 0
        return deserializeValue(data, &index)
    }
    
    private static func serializeInt16(_ buffer: inout [UInt8], _ value: Int16) {
        buffer.append(0xd1)  // int16
        buffer.append(UInt8((value >> 8) & 0xFF))
        buffer.append(UInt8(value & 0xFF))
    }
    
    private static func serializeString(_ buffer: inout [UInt8], _ value: String) {
        guard value.count <= 30 else {
            fatalError("String length exceeds 30 characters")
        }
        
        if value.count < 32 {
            buffer.append(UInt8(0xa0 | value.count))
        } else {
            buffer.append(0xd9)  // str8
            buffer.append(UInt8(value.count))
        }
        
        buffer.append(contentsOf: value.utf8)
    }
    
    private static func serializeMap(_ buffer: inout [UInt8], _ value: [String: MyDataType]) {
        guard value.count <= 15 else {
            fatalError("Map size exceeds 15 elements")
        }
        
        buffer.append(UInt8(0x80 | value.count))
        
        for (key, val) in value {
            serializeString(&buffer, key)
            let serializedValue = serialize(val)
            buffer.append(contentsOf: serializedValue)
        }
    }
    
    private static func deserializeValue(_ data: [UInt8], _ index: inout Int) -> MyDataType {
        let firstByte = data[index]
        index += 1
        
        if (firstByte & 0xe0) == 0xa0 {
            let length = Int(firstByte & 0x1f)
            return .init(deserializeString(data, &index, length: length))
        } else if firstByte == 0xd9 {
            let length = Int(data[index])
            index += 1
            return .init(deserializeString(data, &index, length: length))
        } else if firstByte == 0xd1 {
            return .init(deserializeInt16(data, &index))
        } else if (firstByte & 0xf0) == 0x80 {
            let length = Int(firstByte & 0x0f)
            return .init(deserializeMap(data, &index, length: length))
        } else {
            fatalError("Unsupported MsgPack format")
        }
    }
    
    private static func deserializeInt16(_ data: [UInt8], _ index: inout Int) -> Int16 {
        let highByte = Int16(data[index])
        let lowByte = Int16(data[index + 1])
        index += 2
        return (highByte << 8) | lowByte
    }
    
    private static func deserializeString(_ data: [UInt8], _ index: inout Int, length: Int) -> String {
        let start = index
        let end = index + length
        index = end
        let bytes = data[start..<end]
        return String(bytes: bytes, encoding: .utf8) ?? ""
    }
    
    private static func deserializeMap(_ data: [UInt8], _ index: inout Int, length: Int) -> [String: MyDataType] {
        var map: [String: MyDataType] = [:]
        for _ in 0..<length {
            let key = deserializeValue(data, &index).getValue()
            guard case .string(let keyString) = key else {
                fatalError("Map key must be a string")
            }
            let value = deserializeValue(data, &index)
            map[keyString] = value
        }
        return map
    }
}
