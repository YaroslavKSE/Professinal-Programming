import Foundation

class Triangle {
    let a: Double
    let b: Double
    let c: Double

    init(a: Double, b: Double, c: Double) {
        self.a = a
        self.b = b
        self.c = c
    }

    func area() -> Double {
        let s = (a + b + c) / 2
        return sqrt(s * (s - a) * (s - b) * (s - c))
    }
    
    func height(for side: Character) -> Double? {
        let area = self.area()
        switch side {
        case "a":
            return (2 * area) / a
        case "b":
            return (2 * area) / b
        case "c":
            return (2 * area) / c
        default:
            return nil
        }
    }
}
