import Foundation
import BusinessLogic
import DataAccess
import Presentation

do {
    // Initialize repositories
    let userRepository = try FileUserRepository()
    let productRepository = try FileProductRepository()

    // Initialize services
    let userService = UserService(userRepository: userRepository)
    let productService = ProductService(productRepository: productRepository)

    // Initialize BusinessLogicFacade
    let businessLogicFacade = BusinessLogicFacade()
    
    // Register services with ServiceLocator
    ServiceLocator.shared.register(userService, for: "UserService")
    ServiceLocator.shared.register(productService, for: "ProductService")

    // Initialize and start the console interface
    let consoleInterface = ConsoleInterface(businessLogic: businessLogicFacade)
    consoleInterface.start()
    
} catch {
    print("Failed to set up the application: \(error)")
}