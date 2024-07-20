import Foundation

public struct User: Codable {
    public let id: UUID
    public let email: String
    public var password: String
    public let socialMediaAccount: String?
    
    public init(id: UUID = UUID(), email: String, password: String, socialMediaAccount: String? = nil) {
        self.id = id
        self.email = email
        self.password = password
        self.socialMediaAccount = socialMediaAccount
    }
}