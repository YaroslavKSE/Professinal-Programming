import Foundation

// Example usage
let intData = MyDataType(42)
let stringData = MyDataType("Hello, MsgPack!")
let mapData: [String: MyDataType] = [
    "key1": MyDataType(123),
    "key2": MyDataType("nested string")
]
let mapDataType = MyDataType(mapData)

print("Serializing int data:")
let serializedInt = MsgPackSerializer.serialize(intData)
for byte in serializedInt {
    print(String(format: "%02x", byte), terminator: " ")
}
print("")

print("Serializing string data:")
let serializedString = MsgPackSerializer.serialize(stringData)
for byte in serializedString {
    print(String(format: "%02x", byte), terminator: " ")
}
print("")

print("Serializing map data:")
let serializedMap = MsgPackSerializer.serialize(mapDataType)
for byte in serializedMap {
    print(String(format: "%02x", byte), terminator: " ")
}
print("")

// Save to file
do {
    try FileSaver.saveToFile("output.msgpack", data: mapData)
    print("Serialized data saved to output.msgpack")
    
    // Load from file
    let loadedData = try FileLoader.loadFromFile("output.msgpack")
    print("Loaded data:")
    print(loadedData.description())
    
} catch {
    print("Failed to save or load file: \(error)")
}
