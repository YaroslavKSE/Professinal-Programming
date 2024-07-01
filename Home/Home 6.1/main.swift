import Foundation

func messageGenerator() {
    let dispatcher = MessageDispatcher.shared
    let random = { Double.random(in: 0...100) }
    
    while !Thread.current.isCancelled {
        let msgType = Int.random(in: 0...2)
        switch msgType {
        case 0:
            let msg = GreenMessage(text: "GreenMessage", counter: Int.random(in: 0...100))
            dispatcher.publish(.green(msg))
        case 1:
            let msg = BlueMessage(value1: random(), value2: random())
            dispatcher.publish(.blue(msg))
        case 2:
            let msg = OrangeMessage(text1: "Orange1", text2: "Orange2", number: Int.random(in: 0...100), value: random())
            dispatcher.publish(.orange(msg))
        default:
            break
        }
        Thread.sleep(forTimeInterval: 1)
    }
}

let dispatcher = MessageDispatcher.shared

let greenSubscriberId = dispatcher.subscribe { message in
    if case let .green(msg) = message {
        print("Received GreenMessage: text = \(msg.text), counter = \(msg.counter)")
    }
}

let blueSubscriberId = dispatcher.subscribe { message in
    if case let .blue(msg) = message {
        print("Received BlueMessage: value1 = \(msg.value1), value2 = \(msg.value2)")
    }
}

let orangeSubscriberId = dispatcher.subscribe { message in
    if case let .orange(msg) = message {
        print("Received OrangeMessage: text1 = \(msg.text1), text2 = \(msg.text2), number = \(msg.number), value = \(msg.value)")
    }
}

dispatcher.start()

let generatorQueue = DispatchQueue(label: "messageGenerator.queue", qos: .background)
generatorQueue.async {
    messageGenerator()
}

// Unsubscribe example (after some time)
DispatchQueue.global().asyncAfter(deadline: .now() + 10) {
    dispatcher.unsubscribe(greenSubscriberId)
    dispatcher.unsubscribe(blueSubscriberId)
    dispatcher.unsubscribe(orangeSubscriberId)
}

// Run the dispatcher and generator for a certain duration
DispatchQueue.global().asyncAfter(deadline: .now() + 20) {
    dispatcher.stop()
    print("Dispatcher stopped")
    exit(0)
}

RunLoop.current.run()
