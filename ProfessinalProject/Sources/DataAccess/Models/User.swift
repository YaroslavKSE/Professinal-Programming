import Foundation
import SwiftData

@Model
final class User {
    @Attribute(.unique) let email: String
    var password: String
    let socialMediaAccount: String?
    
    init(email: String, password: String, socialMediaAccount: String? = nil) {
        self.email = email
        self.password = password
        self.socialMediaAccount = socialMediaAccount
    }
}