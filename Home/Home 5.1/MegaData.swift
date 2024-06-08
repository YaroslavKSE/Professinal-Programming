import Foundation

class MegaData {
    var smallArray: [Float]
    var bigArray: [Double]
    
    init() {
        self.smallArray = Array(repeating: 42.0, count: 1024)
        self.bigArray = Array(repeating: 42.0, count: 1024 * 1024)
    }
    
    func reset() {
        self.smallArray = Array(repeating: 42.0, count: 1024)
        self.bigArray = Array(repeating: 42.0, count: 1024 * 1024)
    }
}
