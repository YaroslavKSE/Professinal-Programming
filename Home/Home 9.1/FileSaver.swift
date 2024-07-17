import Foundation

class FileSaver {
    static func saveToFile(_ filename: String, data: MyDataType) throws {
        let serialized = MsgPackSerializer.serialize(data)
        let url = URL(fileURLWithPath: filename)
        try Data(serialized).write(to: url)
    }
}
