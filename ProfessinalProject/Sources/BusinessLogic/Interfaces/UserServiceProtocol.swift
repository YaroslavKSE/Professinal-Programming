import Foundation
import DataAccess

public protocol UserServiceProtocol {
    func registerUser(email: String, password: String) throws
    func loginUser(email: String, password: String) throws -> User
    func registerUserWithSocialMedia(socialMediaAccount: String) throws
    func recoverPassword(email: String) throws
}