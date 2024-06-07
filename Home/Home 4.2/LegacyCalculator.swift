import Foundation

class LegacyCalculator {
    private var megaDelta: Double
    private var megaMultiplier: Double

    private let STRANGE_VAL1 = 6.0
    private let STRANGE_VAL2 = 13.0

    init(megaDelta: Double, megaMultiplier: Double) {
        self.megaDelta = megaDelta
        self.megaMultiplier = megaMultiplier
    }

    func calculatePricePart1() -> Double {
        return STRANGE_VAL1 - megaDelta
    }

    func calculatePricePart2() -> Double {
        return STRANGE_VAL2 * megaMultiplier + 1 - megaDelta
    }

    func getOurTheMostAndMinimalValue() -> Double {
        return megaDelta * megaMultiplier
    }

    func getSomeDocumentRepresentation() -> String {
        return String(format: "The man %.2f who sold the %.2f world",
                      STRANGE_VAL1 - megaDelta,
                      megaMultiplier * STRANGE_VAL2)
    }
}
