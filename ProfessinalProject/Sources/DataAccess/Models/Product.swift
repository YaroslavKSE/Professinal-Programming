import Foundation

public struct Product: Codable {
    public let id: UUID
    public let name: String
    public let category: String
    public let size: String
    public let description: String
    
    public init(id: UUID = UUID(), name: String, category: String, size: String, description: String) {
        self.id = id
        self.name = name
        self.category = category
        self.size = size
        self.description = description
    }
}