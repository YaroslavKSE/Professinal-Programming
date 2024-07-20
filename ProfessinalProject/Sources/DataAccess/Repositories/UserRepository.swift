import Foundation
import SwiftData

protocol UserRepository {
    func createUser(_ user: User) throws
    func getUserByEmail(_ email: String) -> User?
    func updateUser(_ user: User) throws
    func getUserBySocialMediaAccount(_ account: String) -> User?
}

class SwiftDataUserRepository: UserRepository {
    private let context: ModelContext
    
    init(context: ModelContext) {
        self.context = context
    }
    
    func createUser(_ user: User) throws {
        context.insert(user)
        try context.save()
    }
    
    func getUserByEmail(_ email: String) -> User? {
        let descriptor = FetchDescriptor<User>(predicate: #Predicate { $0.email == email })
        return try? context.fetch(descriptor).first
    }
    
    func updateUser(_ user: User) throws {
        try context.save()
    }
    
    func getUserBySocialMediaAccount(_ account: String) -> User? {
        let descriptor = FetchDescriptor<User>(predicate: #Predicate { $0.socialMediaAccount == account })
        return try? context.fetch(descriptor).first
    }
}