import Foundation

class MessageDispatcher {
    static let shared = MessageDispatcher()
    
    private var subscribers: [UUID: (Message) -> Void] = [:]
    private var messageQueue: [Message] = []
    private let queue = DispatchQueue(label: "messageDispatcher.queue", attributes: .concurrent)
    private let semaphore = DispatchSemaphore(value: 0)
    private var running = false
    private var dispatcherThread: Thread?
    
    private init() {}
    
    func start() {
        running = true
        dispatcherThread = Thread {
            self.dispatcherLoop()
        }
        dispatcherThread?.start()
    }
    
    func stop() {
        running = false
        semaphore.signal() // Unblock the loop
        dispatcherThread?.cancel()
    }
    
    func publish(_ message: Message) {
        queue.async(flags: .barrier) {
            self.messageQueue.append(message)
            self.semaphore.signal()
        }
    }
    
    func subscribe(_ subscriber: @escaping (Message) -> Void) -> UUID {
        let id = UUID()
        queue.async(flags: .barrier) {
            self.subscribers[id] = subscriber
        }
        return id
    }
    
    func unsubscribe(_ id: UUID) {
        queue.async(flags: .barrier) {
            self.subscribers.removeValue(forKey: id)
        }
    }
    
    private func dispatcherLoop() {
        while !Thread.current.isCancelled {
            semaphore.wait()
            if !running { break }
            
            queue.sync {
                while !messageQueue.isEmpty {
                    let message = messageQueue.removeFirst()
                    for subscriber in subscribers.values {
                        subscriber(message)
                    }
                }
            }
        }
    }
}
