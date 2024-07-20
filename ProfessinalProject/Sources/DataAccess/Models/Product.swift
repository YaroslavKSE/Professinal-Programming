import Foundation
import SwiftData

@Model
final class Product {
    let name: String
    let category: String
    let size: String
    let description: String
    
    init(name: String, category: String, size: String, description: String) {
        self.name = name
        self.category = category
        self.size = size
        self.description = description
    }
}