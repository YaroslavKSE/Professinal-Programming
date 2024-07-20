import Foundation

public protocol UserRepository {
    func createUser(_ user: User) throws
    func getUserByEmail(_ email: String) -> User?
    func updateUser(_ user: User) throws
    func getUserBySocialMediaAccount(_ account: String) -> User?
}

public class FileUserRepository: UserRepository {
    private let fileManager = FileManager.default
    private let usersFolderURL: URL
    
    public init() throws {
        let documentsURL = fileManager.urls(for: .documentDirectory, in: .userDomainMask).first!
        usersFolderURL = documentsURL.appendingPathComponent("users", isDirectory: true)
        try fileManager.createDirectory(at: usersFolderURL, withIntermediateDirectories: true, attributes: nil)
    }
    
    private func fileURL(for userId: UUID) -> URL {
        return usersFolderURL.appendingPathComponent("\(userId.uuidString).json")
    }
    
    public func createUser(_ user: User) throws {
        let data = try JSONEncoder().encode(user)
        try data.write(to: fileURL(for: user.id))
    }
    
    public func getUserByEmail(_ email: String) -> User? {
        guard let enumerator = fileManager.enumerator(at: usersFolderURL, includingPropertiesForKeys: nil) else {
            return nil
        }
        
        for case let fileURL as URL in enumerator where fileURL.pathExtension == "json" {
            guard let data = try? Data(contentsOf: fileURL),
                  let user = try? JSONDecoder().decode(User.self, from: data) else {
                continue
            }
            
            if user.email == email {
                return user
            }
        }
        
        return nil
    }
    
    public func updateUser(_ user: User) throws {
        let data = try JSONEncoder().encode(user)
        try data.write(to: fileURL(for: user.id))
    }
    
    public func getUserBySocialMediaAccount(_ account: String) -> User? {
        guard let enumerator = fileManager.enumerator(at: usersFolderURL, includingPropertiesForKeys: nil) else {
            return nil
        }
        
        for case let fileURL as URL in enumerator where fileURL.pathExtension == "json" {
            guard let data = try? Data(contentsOf: fileURL),
                  let user = try? JSONDecoder().decode(User.self, from: data) else {
                continue
            }
            
            if user.socialMediaAccount == account {
                return user
            }
        }
        
        return nil
    }
}