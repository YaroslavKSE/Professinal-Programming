import Foundation

class StarmanState: State {
    func handle(command: String) -> State? {
        switch command {
        case "silly":
            return IntroState()
        case "dangerous":
            return ShowMustGoOnState()
        case "fun":
            return InTheEndState()
        default:
            return nil
        }
    }
    
    func getCurrentSong() -> String {
        return "Starman"
    }
}
