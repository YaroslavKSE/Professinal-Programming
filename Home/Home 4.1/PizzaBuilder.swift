import Foundation

class PizzaBuilder {
    private var pizza: Pizza
    private var availableIngredients: [String: Ingredient]

    init(reader: IngredientsReader, filename: String) {
        self.pizza = Pizza()
        self.availableIngredients = reader.readIngredients(from: filename)
    }

    func showIngredients() {
        print("Available ingredients:")
        for (name, ingredient) in availableIngredients {
            print("- \(name) ($\(ingredient.cost))")
        }
    }

    func addIngredientToPizza(_ ingredientName: String) {
        if let ingredient = availableIngredients[ingredientName] {
            pizza.addIngredient(ingredient)
        } else {
            print("Ingredient not found: \(ingredientName)")
        }
    }

    func getProduct() -> Pizza {
        let result = pizza
        self.pizza = Pizza()
        return result
    }
}
