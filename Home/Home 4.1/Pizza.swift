import Foundation

class Pizza {
    private var ingredients: [Ingredient] = []

    func addIngredient(_ ingredient: Ingredient) {
        ingredients.append(ingredient)
    }

    func printPizza() {
        var totalCost = 0.0
        print("Your pizza ingredients:")
        for ingredient in ingredients {
            print("- \(ingredient.name) ($\(ingredient.cost))")
            totalCost += ingredient.cost
        }
        print("Total cost: $\(totalCost)")
    }

    func getIngredients() -> [Ingredient] {
        return ingredients
    }

    func getTotalCost() -> Double {
        return ingredients.reduce(0) { $0 + $1.cost }
    }
}
