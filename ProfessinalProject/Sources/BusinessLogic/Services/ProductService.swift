import Foundation
import DataAccess

public class ProductService: ProductServiceProtocol {
    private let productRepository: ProductRepository
    
    public init(productRepository: ProductRepository) {
        self.productRepository = productRepository
    }
    
    func addProduct(name: String, category: String, size: String, description: String) throws {
        let newProduct = Product(name: name, category: category, size: size, description: description)
        try productRepository.createProduct(newProduct)
    }
    
    func getAllProducts() -> [Product] {
        return productRepository.getAllProducts()
    }
    
    func getProductsByCategory(_ category: String) -> [Product] {
        return productRepository.getProductsByCategory(category)
    }
    
    func getProductsBySize(_ size: String) -> [Product] {
        return productRepository.getProductsBySize(size)
    }
    
    func searchProducts(keyword: String) -> [Product] {
        return productRepository.searchProducts(keyword: keyword)
    }
}