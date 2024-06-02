import Foundation

enum DefaultPizzas: String {
    case margherita = "Margherita"
    case pepperoni = "Pepperoni"
    case vegetarian = "Vegetarian"
}

private struct Commands {
    static let ingredientsFile = "ingredients"
    static let classicalOption = "classical"
    static let customOption = "custom"
    static let doneCommand = "done"
    static let listCommand = "list"
}

func createDefaultPizza(_ type: DefaultPizzas, builder: PizzaBuilder) {
    switch type {
    case .margherita:
        builder.addIngredientToPizza("Cheese")
        builder.addIngredientToPizza("Tomatoes")
    case .pepperoni:
        builder.addIngredientToPizza("Cheese")
        builder.addIngredientToPizza("Pepperoni")
    case .vegetarian:
        builder.addIngredientToPizza("Cheese")
        builder.addIngredientToPizza("Tomatoes")
        builder.addIngredientToPizza("Mushrooms")
        builder.addIngredientToPizza("Peppers")
    }
}

func main() {
    let reader = IngredientsReader()
    let builder = PizzaBuilder(reader: reader, filename: Commands.ingredientsFile)

    print("Do you want to choose a classical pizza or compose a custom one? (classical/custom)")
    if let choice = readLine() {
        if choice.lowercased() == Commands.classicalOption {
            print("Choose a classical pizza: Margherita, Pepperoni, Vegetarian")
            if let pizzaType = readLine(), let defaultPizza = DefaultPizzas(rawValue: pizzaType) {
                createDefaultPizza(defaultPizza, builder: builder)
                let pizza = builder.getProduct()
                pizza.printPizza()
            } else {
                print("Invalid choice.")
            }
        } else if choice.lowercased() == Commands.customOption {
            while true {
                print("Enter an ingredient (or 'done' to finish, 'list' to show ingredients): ")
                if let input = readLine() {
                    if input.lowercased() == Commands.doneCommand {
                        break
                    } else if input.lowercased() == Commands.listCommand {
                        builder.showIngredients()
                    } else {
                        builder.addIngredientToPizza(input)
                    }
                }
            }
            let pizza = builder.getProduct()
            pizza.printPizza()
        } else {
            print("Invalid choice.")
        }
    }
}

main()
