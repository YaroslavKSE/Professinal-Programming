import Foundation

func getFavoriteWords() -> [String] {
    var words: [String] = []
    
    for i in 1...5 {
        print("Enter favorite word \(i): ", terminator: "")
        if let word = readLine(), !word.isEmpty {
            words.append(word)
        }
    }
    
    return words
}

func processWord(_ word: String, group: DispatchGroup) {
    defer {
        group.leave()
    }
    
    guard let firstChar = word.lowercased().first else {
        print("Invalid word")
        return
    }
    
    let config = Configuration.shared
    
    guard let (preWord, postWord) = config.getPrePostWords(for: firstChar) else {
        print("No configuration found for word \(word)")
        return
    }
    
    sleep(1)
    print("\(preWord) \(word) \(postWord)")
}

let words = getFavoriteWords()
let dispatchGroup = DispatchGroup()

for word in words {
    dispatchGroup.enter()
    DispatchQueue.global().async {
        processWord(word, group: dispatchGroup)
    }
}

dispatchGroup.wait()
print("All threads completed.")
