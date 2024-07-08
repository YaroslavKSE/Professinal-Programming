import Foundation

class LetItBeState: State {
    func handle(command: String) -> State? {
        switch command {
        case "dangerous":
            return IntroState()
        case "silly":
            return ShowMustGoOnState()
        default:
            return nil
        }
    }
    
    func getCurrentSong() -> String {
        return "Let it be"
    }
}
