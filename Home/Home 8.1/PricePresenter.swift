class PricePresenter<Priority: Numeric & LosslessStringConvertible> {
    func printTotalPrice<T1: PricedItem, T2: PricedItem>(_ obj1: T1, _ obj2: T2, priority: Priority) {
        guard let priorityValue = Double("\(priority)") else {
            print("Invalid priority value")
            return
        }
        let totalPrice = priorityValue * obj1.coefficient * obj1.basePrice + obj2.coefficient * obj2.basePrice
        print("Total Price: \(totalPrice)")
    }
}
