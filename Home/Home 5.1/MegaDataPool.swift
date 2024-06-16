import Foundation

enum MegaDataPoolError: Error {
    case noAvailableObjects
    case invalidObject
}

class MegaDataPool {
    private let poolSize: Int
    private var pool: [MegaData]
    private var used: [Bool]

    init(poolSize: Int) {
        self.poolSize = poolSize
        self.pool = Array(repeating: MegaData(), count: poolSize)
        self.used = Array(repeating: false, count: poolSize)
    }

    func acquire() throws -> MegaData {
        for i in 0..<poolSize {
            if !used[i] {
                used[i] = true
                return pool[i]
            }
        }
        throw MegaDataPoolError.noAvailableObjects
    }

    func release(_ data: MegaData) throws {
        if let index = pool.firstIndex(where: { $0 === data }) {
            used[index] = false
            pool[index].reset()
        } else {
            throw MegaDataPoolError.invalidObject
        }
    }

    func size() -> Int {
        return poolSize
    }

    func usedSize() -> Int {
        return used.filter { $0 }.count
    }
}
