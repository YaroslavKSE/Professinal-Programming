class Milk: PricedItem {
    var coefficient: Double
    var basePrice: Double

    init(coefficient: Double, basePrice: Double) {
        self.coefficient = coefficient
        self.basePrice = basePrice
    }
}