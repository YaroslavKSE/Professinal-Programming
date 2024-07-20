import Foundation
import DataAccess

public class BusinessLogicFacade {
    private let serviceLocator: ServiceLocator
    
    public init(serviceLocator: ServiceLocator = .shared) {
        self.serviceLocator = serviceLocator
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
    public func addProduct(name: String, category: String, size: String, description: String) throws {
        try productService.addProduct(name: name, category: category, size: size, description: description)
    }
    
    public func getAllProducts() -> [Product] {
        return productService.getAllProducts()
    }
    
    public func getProductsByCategory(_ category: String) -> [Product] {
        return productService.getProductsByCategory(category)
    }
    
    public func getProductsBySize(_ size: String) -> [Product] {
        return productService.getProductsBySize(size)
    }
    
    public func searchProducts(keyword: String) -> [Product] {
        return productService.searchProducts(keyword: keyword)
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
}