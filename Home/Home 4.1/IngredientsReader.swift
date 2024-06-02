import Foundation

class IngredientsReader {
    func readIngredients(from filename: String) -> [String: Ingredient] {
        var ingredients: [String: Ingredient] = [:]
        guard let fileURL = Bundle.main.url(forResource: filename, withExtension: "txt"),
              let fileContents = try? String(contentsOf: fileURL) else {
            print("Unable to open file: \(filename)")
            return ingredients
        }

        let lines = fileContents.split(separator: "\n")
        for line in lines {
            let parts = line.split(separator: " ")
            if parts.count == 2, let cost = Double(parts[1]) {
                let name = String(parts[0])
                ingredients[name] = Ingredient(name: name, cost: cost)
            } else {
                print("Invalid line format: \(line)")
            }
        }
        return ingredients
    }
}
