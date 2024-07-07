import Foundation

class Configuration {
    static let shared = Configuration()
    
    private var config: [Character: (String, String)] = [:]
    
    private init() {
        loadConfiguration()
    }
    
    private func loadConfiguration() {
        guard let path = Bundle.main.path(forResource: "config", ofType: "txt") else {
            print("Configuration file not found!")
            return
        }
        
        do {
            let content = try String(contentsOfFile: path)
            let lines = content.split(separator: "\n")
            
            for line in lines {
                let parts = line.split(separator: " ")
                guard parts.count == 3 else { continue }
                let range = parts[0]
                let preWord = String(parts[1])
                let postWord = String(parts[2])
                
                for char in range {
                    config[char] = (preWord, postWord)
                }
            }
        } catch {
            print("Error reading configuration file: \(error)")
        }
    }
    
    func getPrePostWords(for char: Character) -> (String, String)? {
        return config[char]
    }
}
