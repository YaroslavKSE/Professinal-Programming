import Foundation

// Function to read input from the console and convert it to Double
func readCoefficient(name: String) -> Double? {
    print("Enter coefficient \(name):")
    guard let input = readLine(), let number = Double(input) else {
        print("Invalid input. Please enter a valid number.")
        return nil
    }
    return number
}

// Function to calculate the roots of the quadratic equation
func calculateQuadraticRoots(a: Double, b: Double, c: Double) -> (root1: Double?, root2: Double?) {
    let discriminant = b * b - 4 * a * c
    guard discriminant >= 0 else {
        return (nil, nil)
    }
    let sqrtDiscriminant = discriminant.squareRoot()
    let root1 = (-b + sqrtDiscriminant) / (2 * a)
    let root2 = (-b - sqrtDiscriminant) / (2 * a)
    return (root1, discriminant == 0 ? nil : root2)
}

// Function to print the roots of the quadratic equation
func printQuadraticRoots(roots: (root1: Double?, root2: Double?)) {
    if let root1 = roots.root1, let root2 = roots.root2 {
        print("The roots are real and different.")
        print("Root 1: \(root1)")
        print("Root 2: \(root2)")
    } else if let root = roots.root1 {
        print("The roots are real and the same.")
        print("Root: \(root)")
    } else {
        print("There are no roots for this equation.")
    }
}

// Main program
func main() {
    print("Solve the quadratic equation ax^2 + bx + c = 0")

    guard let a = readCoefficient(name: "a"), a != 0 else {
        print("Coefficient a cannot be zero.")
        return
    }

    guard let b = readCoefficient(name: "b") else {
        return
    }

    guard let c = readCoefficient(name: "c") else {
        return
    }

    let roots = calculateQuadraticRoots(a: a, b: b, c: c)
    printQuadraticRoots(roots: roots)
}

// Run the program
main()
