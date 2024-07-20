import Foundation

public class ServiceLocator {
    public static let shared = ServiceLocator()
    
    private var services: [String: Any] = [:]
    
    private init() {}
    
    public func register<T>(_ service: T, for key: String) {
        services[key] = service
    }
    
    public func resolve<T>(_ type: T.Type, for key: String) -> T? {
        return services[key] as? T
    }
}