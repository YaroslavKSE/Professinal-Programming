import Foundation
import DataAccess

public protocol ProductServiceProtocol {
    func getAllProducts() throws -> [Product]
    func getProductsByCategory(_ category: String) throws -> [Product]
    func getProductsBySize(_ size: String) throws -> [Product]
    func searchProducts(keyword: String) throws -> [Product]
    func createProduct(name: String, category: String, size: String, description: String) throws -> Product
}