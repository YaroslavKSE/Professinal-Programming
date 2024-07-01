import Foundation

struct GreenMessage {
    let text: String
    let counter: Int
}

struct BlueMessage {
    let value1: Double
    let value2: Double
}

struct OrangeMessage {
    let text1: String
    let text2: String
    let number: Int
    let value: Double
}

enum Message {
    case green(GreenMessage)
    case blue(BlueMessage)
    case orange(OrangeMessage)
}
