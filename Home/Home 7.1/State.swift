protocol State {
    func handle(command: String) -> State?
    func getCurrentSong() -> String
}
