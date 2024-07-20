import Foundation

public enum ProductError: Error {
    case invalidInput(String)
    case productNotFound
    case creationFailed(String)

    public var description: String {
        switch self {
        case .invalidInput(let details):
            return "Invalid input: \(details)"
        case .productNotFound:
            return "Product not found"
        case .creationFailed(let reason):
            return "Failed to create product: \(reason)"
        }
    }
}