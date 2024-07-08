import Foundation

class InTheEndState: State {
    func handle(command: String) -> State? {
        return nil
    }
    
    func getCurrentSong() -> String {
        return "But in the end, it doesn't even matter"
    }
}
