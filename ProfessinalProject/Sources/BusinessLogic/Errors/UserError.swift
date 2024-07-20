import Foundation

public enum UserError: Error {
    case invalidInput(String)
    case emailAlreadyExists
    case userNotFound
    case invalidCredentials
    case socialMediaAccountAlreadyExists
    case passwordRecoveryFailed(String)

    public var errorDescription: String {
        switch self {
        case .invalidInput(let details):
            return "Invalid input: \(details)"
        case .emailAlreadyExists:
            return "A user with this email already exists"
        case .userNotFound:
            return "User not found"
        case .invalidCredentials:
            return "Invalid email or password"
        case .socialMediaAccountAlreadyExists:
            return "A user with this social media account already exists"
        case .passwordRecoveryFailed(let reason):
            return "Password recovery failed: \(reason)"
        }
    }
}