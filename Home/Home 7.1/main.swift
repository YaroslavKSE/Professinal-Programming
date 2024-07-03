import Foundation

let player = PlayerContext()
let commands = ["fun", "dangerous", "silly", "sad"]

while true {
    print("Enter a command (sad, fun, silly, dangerous): ", terminator: "")
    if let input = readLine(), commands.contains(input) {
        player.request(command: input)
    } else {
        print("Invalid command. Try again.")
    }
}
