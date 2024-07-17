import Foundation

class MyDataType {
    enum ValueType {
        case int16(Int16)
        case string(String)
        case map([String: MyDataType])
    }
    
    private var value: ValueType
    
    init() {
        self.value = .int16(0)
    }
    
    init(_ value: Int16) {
        self.value = .int16(value)
    }
    
    init(_ value: String) {
        self.value = .string(value)
    }
    
    init(_ value: [String: MyDataType]) {
        self.value = .map(value)
    }
    
    func getValue() -> ValueType {
        return value
    }
    
    func description() -> String {
        switch value {
        case .int16(let value):
            return "\(value)"
        case .string(let value):
            return "\"\(value)\""
        case .map(let value):
            let mapDescription = value.map { key, val in
                return "\"\(key)\": \(val.description())"
            }.joined(separator: ", ")
            return "{\(mapDescription)}"
        }
    }
}
