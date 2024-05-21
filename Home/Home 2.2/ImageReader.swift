import Foundation

class ImageReader {
    static func read(from inputFilename: String) -> Image? {
        guard let content = try? String(contentsOfFile: inputFilename) else {
            print("Failed to open file: \(inputFilename)")
            return nil
        }

        let lines = content.split(separator: "\n")
        guard lines.count == imageSize else {
            print("Invalid input format: not enough lines.")
            return nil
        }

        let image = Image()
        for (i, line) in lines.enumerated() {
            let pixels = line.split(separator: " ")
            guard pixels.count == imageSize else {
                print("Invalid input pixel format in row \(i + 1).")
                return nil
            }

            for (j, pixel) in pixels.enumerated() {
                let components = pixel.split(separator: ",")
                guard components.count == 3,
                      let r = Int(components[0]),
                      let g = Int(components[1]),
                      let b = Int(components[2]) else {
                    print("Invalid input pixel format in row \(i + 1), pixel \(j + 1).")
                    return nil
                }

                image.pixels[i][j] = Color(r: r, g: g, b: b)
            }
        }

        return image
    }
}
