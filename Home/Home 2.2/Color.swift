struct Color: Equatable {
    var r: Int
    var g: Int
    var b: Int

    func isValid() -> Bool {
        return (0...255).contains(r) && (0...255).contains(g) && (0...255).contains(b)
    }
}
