import Foundation

let imageSize = 16

class Image {
    var pixels: [[Color]]

    init() {
        self.pixels = Array(repeating: Array(repeating: Color(r: 0, g: 0, b: 0), count: imageSize), count: imageSize)
    }

    func applyFavoriteColor(favoriteColor: Color, unfavoriteColor: Color? = nil) {
        for i in 0..<imageSize {
            for j in 0..<imageSize {
                if let unfavoriteColor = unfavoriteColor, pixels[i][j] == unfavoriteColor {
                    pixels[i][j] = favoriteColor
                }
                if pixels[i][j] == favoriteColor {
                    if i > 0 {
                        pixels[i - 1][j] = favoriteColor // top pixel
                    }
                    if j > 0 {
                        pixels[i][j - 1] = favoriteColor // left pixel
                    }
                }
            }
        }
    }
}
