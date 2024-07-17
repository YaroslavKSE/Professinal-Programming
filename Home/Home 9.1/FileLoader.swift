import Foundation

class FileLoader {
    static func loadFromFile(_ filename: String) throws -> MyDataType {
        let url = URL(fileURLWithPath: filename)
        let data = try Data(contentsOf: url)
        return MsgPackSerializer.deserialize([UInt8](data))
    }
}
