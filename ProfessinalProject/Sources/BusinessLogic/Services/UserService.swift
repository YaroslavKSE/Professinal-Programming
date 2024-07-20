import Foundation
import DataAccess

public class UserService: UserServiceProtocol {
    private let userRepository: UserRepository
    
    public init(userRepository: UserRepository) {
        self.userRepository = userRepository
    }
    
    public func registerUser(email: String, password: String) throws {
        guard !email.isEmpty, !password.isEmpty else {
            throw UserError.invalidInput
        }
        
        if userRepository.getUserByEmail(email) != nil {
            throw UserError.emailAlreadyExists
        }
        
        let newUser = User(email: email, password: password)
        try userRepository.createUser(newUser)
    }
    
    public func loginUser(email: String, password: String) throws -> User {
        guard let user = userRepository.getUserByEmail(email) else {
            throw UserError.userNotFound
        }
        
        if user.password != password {
            throw UserError.invalidCredentials
        }
        
        return user
    }
    
    public func registerUserWithSocialMedia(socialMediaAccount: String) throws {
        guard !socialMediaAccount.isEmpty else {
            throw UserError.invalidInput
        }
        
        if userRepository.getUserBySocialMediaAccount(socialMediaAccount) != nil {
            throw UserError.socialMediaAccountAlreadyExists
        }
        
        let newUser = User(email: socialMediaAccount, password: "", socialMediaAccount: socialMediaAccount)
        try userRepository.createUser(newUser)
    }
    
    public func recoverPassword(email: String) throws {
        guard let user = userRepository.getUserByEmail(email) else {
            throw UserError.userNotFound
        }
        
        // In a real application, generate a password reset token and send an email here
        // For this console application, just print the password
        print("Password recovery for \(email): Your password is \(user.password)")
    }
}

enum UserError: Error {
    case invalidInput
    case emailAlreadyExists
    case userNotFound
    case invalidCredentials
    case socialMediaAccountAlreadyExists
}