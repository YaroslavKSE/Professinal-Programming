import Foundation

class IntroState: State {
    func handle(command: String) -> State? {
        switch command {
        case "dangerous":
            return LetItBeState()
        case "fun":
            return StarmanState()
        case "sad":
            return InTheEndState()
        default:
            return nil
        }
    }
    
    func getCurrentSong() -> String {
        return "Intro"
    }
}
