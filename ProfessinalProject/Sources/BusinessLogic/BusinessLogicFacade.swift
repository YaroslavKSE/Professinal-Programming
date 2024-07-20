import Foundation
import DataAccess

public class BusinessLogicFacade {
    private let serviceLocator: ServiceLocator
    
    public init(serviceLocator: ServiceLocator = .shared) {
        self.serviceLocator = serviceLocator
    }

        private var userService: UserServiceProtocol {
        guard let service = serviceLocator.resolve(UserServiceProtocol.self, for: "UserService") else {
            fatalError("UserService not registered")
        }
        return service
    }
    
    private var productService: ProductServiceProtocol {
        guard let service = serviceLocator.resolve(ProductServiceProtocol.self, for: "ProductService") else {
            fatalError("ProductService not registered")
        }
        return service
    }
    
    // User Management
    public func registerUser(email: String, password: String) throws {
        try userService.registerUser(email: email, password: password)
    }
    
    public func loginUser(email: String, password: String) throws -> User {
        return try userService.loginUser(email: email, password: password)
    }
    
    public func registerUserWithSocialMedia(socialMediaAccount: String) throws {
        try userService.registerUserWithSocialMedia(socialMediaAccount: socialMediaAccount)
    }
    
    public func recoverPassword(email: String) throws {
        try userService.recoverPassword(email: email)
    }
    
    // Product Catalog
    public func createProduct(name: String, category: String, size: String, description: String) throws -> Product {
        return try productService.createProduct(name: name, category: category, size: size, description: description)
    }
    
    public func getAllProducts() throws -> [Product] {
        return try productService.getAllProducts()
    }
    
    public func getProductsByCategory(_ category: String) throws -> [Product] {
        return try productService.getProductsByCategory(category)
    }
    
    public func getProductsBySize(_ size: String) throws -> [Product] {
        return try productService.getProductsBySize(size)
    }
    
    public func searchProducts(keyword: String) throws -> [Product] {
        return try productService.searchProducts(keyword: keyword)
    }
    

}