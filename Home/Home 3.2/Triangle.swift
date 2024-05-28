import Foundation

enum TriangleError: Error, Equatable {
    case invalidSides(String)
}

enum TriangleSide {
    case a, b, c
}

class Triangle {
    let a: Double
    let b: Double
    let c: Double

    init(a: Double, b: Double, c: Double) throws {
        self.a = a
        self.b = b
        self.c = c
        try validateSides()
    }

    private func validateSides() throws {
        guard a > 0, b > 0, c > 0 else {
            throw TriangleError.invalidSides("Sides must be positive numbers.")
        }
        guard a + b > c, a + c > b, b + c > a else {
            throw TriangleError.invalidSides("The given sides do not form a valid triangle.")
        }
    }

    func calculateArea() -> Double {
        let s = (a + b + c) / 2
        return sqrt(s * (s - a) * (s - b) * (s - c))
    }
    
    func height(for side: TriangleSide) -> Double {
        let area = calculateArea()
        switch side {
        case .a:
            return (2 * area) / a
        case .b:
            return (2 * area) / b
        case .c:
            return (2 * area) / c
        }
    }
}
