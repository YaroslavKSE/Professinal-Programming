import Foundation

public protocol ProductRepository {
    func createProduct(_ product: Product) throws
    func getAllProducts() -> [Product]
    func getProductsByCategory(_ category: String) -> [Product]
    func getProductsBySize(_ size: String) -> [Product]
    func searchProducts(keyword: String) -> [Product]
}

public class FileProductRepository: ProductRepository {
    private let fileManager = FileManager.default
    private let productsFolderURL: URL
    
    public init() throws {
        let documentsURL = fileManager.urls(for: .documentDirectory, in: .userDomainMask).first!
        productsFolderURL = documentsURL.appendingPathComponent("products", isDirectory: true)
        try fileManager.createDirectory(at: productsFolderURL, withIntermediateDirectories: true, attributes: nil)
    }
    
    private func fileURL(for productId: UUID) -> URL {
        return productsFolderURL.appendingPathComponent("\(productId.uuidString).json")
    }
    
    public func getAllProducts() -> [Product] {
        guard let enumerator = fileManager.enumerator(at: productsFolderURL, includingPropertiesForKeys: nil) else {
            return []
        }
        
        var products: [Product] = []
        
        for case let fileURL as URL in enumerator where fileURL.pathExtension == "json" {
            guard let data = try? Data(contentsOf: fileURL),
                  let product = try? JSONDecoder().decode(Product.self, from: data) else {
                continue
            }
            
            products.append(product)
        }
        
        return products
    }
    
    public func getProductsByCategory(_ category: String) -> [Product] {
        return getAllProducts().filter { $0.category.lowercased() == category.lowercased() }
    }
    
    public func getProductsBySize(_ size: String) -> [Product] {
        return getAllProducts().filter { $0.size.lowercased() == size.lowercased() }
    }
    
    public func searchProducts(keyword: String) -> [Product] {
        let lowercasedKeyword = keyword.lowercased()
        return getAllProducts().filter { product in
            product.name.lowercased().contains(lowercasedKeyword) ||
            product.description.lowercased().contains(lowercasedKeyword)
        }
    }
    public func createProduct(_ product: Product) throws {
    let data = try JSONEncoder().encode(product)
    try data.write(to: fileURL(for: product.id))
    }
}