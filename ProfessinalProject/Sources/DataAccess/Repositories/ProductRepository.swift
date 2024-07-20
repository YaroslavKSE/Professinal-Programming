import Foundation
import SwiftData

protocol ProductRepository {
    func createProduct(_ product: Product) throws
    func getAllProducts() -> [Product]
    func getProductsByCategory(_ category: String) -> [Product]
    func getProductsBySize(_ size: String) -> [Product]
    func searchProducts(keyword: String) -> [Product]
}

class SwiftDataProductRepository: ProductRepository {
    private let context: ModelContext
    
    init(context: ModelContext) {
        self.context = context
    }
    
    func createProduct(_ product: Product) throws {
        context.insert(product)
        try context.save()
    }
    
    func getAllProducts() -> [Product] {
        let descriptor = FetchDescriptor<Product>()
        return (try? context.fetch(descriptor)) ?? []
    }
    
    func getProductsByCategory(_ category: String) -> [Product] {
        let descriptor = FetchDescriptor<Product>(predicate: #Predicate { $0.category == category })
        return (try? context.fetch(descriptor)) ?? []
    }
    
    func getProductsBySize(_ size: String) -> [Product] {
        let descriptor = FetchDescriptor<Product>(predicate: #Predicate { $0.size == size })
        return (try? context.fetch(descriptor)) ?? []
    }
    
    func searchProducts(keyword: String) -> [Product] {
        let descriptor = FetchDescriptor<Product>(predicate: #Predicate {
            $0.name.contains(keyword) || $0.description.contains(keyword)
        })
        return (try? context.fetch(descriptor)) ?? []
    }
}