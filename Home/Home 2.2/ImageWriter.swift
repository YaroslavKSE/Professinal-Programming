import Foundation

class ImageWriter {
    static func write(_ image: Image, to outputFilename: String) {
        var content = ""
        for row in image.pixels {
            content += row.map { "\($0.r),\($0.g),\($0.b)" }.joined(separator: " ") + "\n"
        }

        do {
            try content.write(toFile: outputFilename, atomically: true, encoding: .utf8)
        } catch {
            print("Failed to write to file \(outputFilename): \(error)")
        }
    }
}
