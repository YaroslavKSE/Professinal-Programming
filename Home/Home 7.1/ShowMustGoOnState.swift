import Foundation

class ShowMustGoOnState: State {
    func handle(command: String) -> State? {
        switch command {
        case "sad":
            return LetItBeState()
        case "fun":
            return StarmanState()
        default:
            return nil
        }
    }
    
    func getCurrentSong() -> String {
        return "Show must go on"
    }
}
