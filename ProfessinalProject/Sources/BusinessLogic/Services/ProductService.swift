import Foundation
import DataAccess

public class ProductService: ProductServiceProtocol {
    private let productRepository: ProductRepository
    
    public init(productRepository: ProductRepository) {
        self.productRepository = productRepository
    }
    
    public func addProduct(name: String, category: String, size: String, description: String) throws {
        let newProduct = Product(name: name, category: category, size: size, description: description)
        try productRepository.createProduct(newProduct)
    }
    
    public func getAllProducts() -> [Product] {
        return productRepository.getAllProducts()
    }
    
    public func getProductsByCategory(_ category: String) -> [Product] {
        return productRepository.getProductsByCategory(category)
    }
    
    public func getProductsBySize(_ size: String) -> [Product] {
        return productRepository.getProductsBySize(size)
    }
    
    public func searchProducts(keyword: String) -> [Product] {
        return productRepository.searchProducts(keyword: keyword)
    }
    public func createProduct(name: String, category: String, size: String, description: String) throws -> Product {
    let newProduct = Product(name: name, category: category, size: size, description: description)
    try productRepository.createProduct(newProduct)
    return newProduct
    }
}