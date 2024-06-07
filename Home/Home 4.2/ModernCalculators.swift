import Foundation

protocol BaseMegaCalculator {
    func getPrice() -> Double
    func getMinimalValue() -> Double
    func getReport() -> String
}

class ConstantCalculator: BaseMegaCalculator {
    func getPrice() -> Double {
        return 0.0
    }

    func getMinimalValue() -> Double {
        return 0.0
    }

    func getReport() -> String {
        return "Sound of Silence"
    }
}

class MyCoolCalculator: BaseMegaCalculator {
    private var coef1: Double
    private var coef2: Double
    private var coef3: Double

    private let VAL1 = 12.0
    private let VAL2 = 3.0
    private let VAL3 = 0.05

    init(coef1: Double, coef2: Double, coef3: Double) {
        self.coef1 = coef1
        self.coef2 = coef2
        self.coef3 = coef3
    }

    func getPrice() -> Double {
        return coef1 * VAL1 + coef2 * VAL2 - coef3 * VAL3
    }

    func getMinimalValue() -> Double {
        return min(coef1 * VAL1, coef2 * VAL2)
    }

    func getReport() -> String {
        return String(format: "Some1 %.2f, another2 %.3f, and3 %.2f", coef1, coef2, coef3 * VAL2)
    }
}
