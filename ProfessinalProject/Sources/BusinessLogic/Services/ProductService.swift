import Foundation
import DataAccess

public class ProductService: ProductServiceProtocol {
    private let productRepository: ProductRepository
    
    public init(productRepository: ProductRepository) {
        self.productRepository = productRepository
    }
    
    public func createProduct(name: String, category: String, size: String, description: String) throws -> Product {
        guard !name.isEmpty && !category.isEmpty && !size.isEmpty && !description.isEmpty else {
            throw ProductError.invalidInput("All product fields must be non-empty")
        }
        
        let newProduct = Product(name: name, category: category, size: size, description: description)
        do {
            try productRepository.createProduct(newProduct)
            return newProduct
        } catch {
            throw ProductError.creationFailed("Failed to save product: \(error.localizedDescription)")
        }
    }
    
    public func getAllProducts() throws -> [Product] {
        let products = productRepository.getAllProducts()
        if products.isEmpty {
            throw ProductError.productNotFound
        }
        return products
    }
    
    public func getProductsByCategory(_ category: String) throws -> [Product] {
        guard !category.isEmpty else {
            throw ProductError.invalidInput("Category cannot be empty")
        }
        let products = productRepository.getProductsByCategory(category)
        if products.isEmpty {
            throw ProductError.productNotFound
        }
        return products
    }
    
    public func getProductsBySize(_ size: String) throws -> [Product] {
        guard !size.isEmpty else {
            throw ProductError.invalidInput("Size cannot be empty")
        }
        let products = productRepository.getProductsBySize(size)
        if products.isEmpty {
            throw ProductError.productNotFound
        }
        return products
    }
    
    public func searchProducts(keyword: String) throws -> [Product] {
        guard !keyword.isEmpty else {
            throw ProductError.invalidInput("Search keyword cannot be empty")
        }
        let products = productRepository.searchProducts(keyword: keyword)
        if products.isEmpty {
            throw ProductError.productNotFound
        }
        return products
    }
}