import Foundation

func main() {
    print("Enter input file name: ", terminator: "")
    guard let inputFilename = readLine() else {
        print("Invalid input.")
        return
    }

    print("Enter your favorite color (r g b): ", terminator: "")
    guard let favoriteColorInput = readLine()?.split(separator: " "),
          favoriteColorInput.count == 3,
          let r = Int(favoriteColorInput[0]),
          let g = Int(favoriteColorInput[1]),
          let b = Int(favoriteColorInput[2]) else {
        print("Invalid color input.")
        return
    }
    let favoriteColor = Color(r: r, g: g, b: b)
    guard favoriteColor.isValid() else {
        print("Invalid color input. Each component should be between 0 and 255.")
        return
    }

    print("Enter your unfavorite color (r g b) or press Enter to skip: ", terminator: "")
    let unfavoriteColor: Color?
    if let unfavoriteColorInput = readLine(), !unfavoriteColorInput.isEmpty {
        let unfavoriteColorComponents = unfavoriteColorInput.split(separator: " ")
        if unfavoriteColorComponents.count == 3,
           let ur = Int(unfavoriteColorComponents[0]),
           let ug = Int(unfavoriteColorComponents[1]),
           let ub = Int(unfavoriteColorComponents[2]) {
            let color = Color(r: ur, g: ug, b: ub)
            if color.isValid() {
                unfavoriteColor = color
            } else {
                print("Invalid unfavorite color input. Each component should be between 0 and 255.")
                return
            }
        } else {
            print("Invalid unfavorite color input.")
            return
        }
    } else {
        unfavoriteColor = nil
    }

    print("Enter output file name: ", terminator: "")
    guard let outputFilename = readLine() else {
        print("Invalid input.")
        return
    }

    guard let image = ImageReader.read(from: inputFilename) else {
        return
    }

    image.applyFavoriteColor(favoriteColor: favoriteColor, unfavoriteColor: unfavoriteColor)

    ImageWriter.write(image, to: outputFilename)

    print("Image processing complete. Output written to \(outputFilename).")
}

main()
