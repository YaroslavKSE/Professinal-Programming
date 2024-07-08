import Foundation

class PlayerContext {
    private var state: State
    
    init() {
        self.state = IntroState()
        print("Current song: \(self.state.getCurrentSong())")
    }
    
    func request(command: String) {
        if let newState = state.handle(command: command) {
            self.state = newState
            print("Current song: \(self.state.getCurrentSong())")
        } else if state is InTheEndState {
            print("Program terminated.")
            exit(0)
        } else {
            print("Replay current song: \(self.state.getCurrentSong())")
        }
    }
}
