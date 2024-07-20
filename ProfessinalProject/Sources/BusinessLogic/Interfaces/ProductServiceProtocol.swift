import Foundation
import DataAccess

public protocol ProductServiceProtocol {
    func addProduct(name: String, category: String, size: String, description: String) throws
    func getAllProducts() -> [Product]
    func getProductsByCategory(_ category: String) -> [Product]
    func getProductsBySize(_ size: String) -> [Product]
    func searchProducts(keyword: String) -> [Product]
    func createProduct(name: String, category: String, size: String, description: String) throws -> Product
}