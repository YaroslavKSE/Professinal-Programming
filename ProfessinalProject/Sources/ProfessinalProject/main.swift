import Foundation
import SwiftData
import BusinessLogic
import DataAccess
import Presentation

// Set up the ModelContainer
let schema = Schema([
    User.self,
    Product.self
])

let modelConfiguration = ModelConfiguration(schema: schema, isStoredInMemoryOnly: false)

do {
    let container = try ModelContainer(for: schema, configurations: [modelConfiguration])
    let context = ModelContext(container)
    
    let userRepository = SwiftDataUserRepository(context: context)
    let productRepository = SwiftDataProductRepository(context: context)

    let userService = UserService(userRepository: userRepository)
    let productService = ProductService(productRepository: productRepository)

    ServiceLocator.shared.register(userService, for: "UserService")
    ServiceLocator.shared.register(productService, for: "ProductService")

    let businessLogicFacade = BusinessLogicFacade()
    
    // Create and start the console interface
    let consoleInterface = ConsoleInterface(businessLogic: businessLogicFacade)
    consoleInterface.start()
    
} catch {
    print("Failed to set up the application: \(error)")
}