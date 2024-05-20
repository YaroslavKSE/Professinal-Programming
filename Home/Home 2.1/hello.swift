import Foundation

struct UserStat: Codable {
    var name: String
    var count: Int
}

class UserStatsManager {
    private var userStats: [String: UserStat] = [:]
    private let filename = "user_stats.txt"
    
    init() {
        loadUserStats()
    }
    
    private func loadUserStats() {
        if let data = try? String(contentsOfFile: filename) {
            data.split(separator: "\n").forEach { line in
                let parts = line.split(separator: " ")
                if parts.count == 2, let count = Int(parts[1]) {
                    let stat = UserStat(name: String(parts[0]), count: count)
                    userStats[stat.name] = stat
                }
            }
        }
    }
    
    private func saveUserStats() {
        let data = userStats.values.map { "\($0.name) \($0.count)" }.joined(separator: "\n")
        do {
            try data.write(toFile: filename, atomically: true, encoding: .utf8)
        } catch {
            print("Failed to write to file \(filename): \(error)")
        }
    }
    
    func greetUser(_ name: String) {
        if name == "bread" {
            userStats.removeAll()
            print("All user history has been exterminated!")
            saveUserStats()
            return
        }
        
        if userStats[name] == nil {
            print("Welcome, \(name)!")
            userStats[name] = UserStat(name: name, count: 1)
        } else {
            userStats[name]!.count += 1
            print("Hello again (x\(userStats[name]!.count)), \(name)!")
        }
        saveUserStats()
    }
    
    func resetUserStats(_ name: String) {
        userStats.removeValue(forKey: name)
        print("Statistics for \(name) have been reset.")
        saveUserStats()
    }
}

let arguments = CommandLine.arguments

guard arguments.count >= 2 && arguments.count <= 3 else {
    print("Usage: \(arguments[0]) <name> [delete]")
    exit(1)
}

let name = arguments[1]
let deleteStats = arguments.count == 3 && arguments[2] == "delete"

let manager = UserStatsManager()

if deleteStats {
    manager.resetUserStats(name)
} else {
    manager.greetUser(name)
}
