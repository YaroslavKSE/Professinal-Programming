import Foundation

// Function to read input from the console and convert it to Double
func readCoefficient(prompt: String) -> Double? {
    print(prompt)
    guard let input = readLine(), let number = Double(input) else {
        print("Invalid input. Please enter a valid number.")
        return nil
    }
    return number
}

// Function to calculate the roots of the quadratic equation
func solveQuadraticEquation(a: Double, b: Double, c: Double) {
    let discriminant = b * b - 4 * a * c
    let sqrtDiscriminant = discriminant.squareRoot()

    if discriminant > 0 {
        let root1 = (-b + sqrtDiscriminant) / (2 * a)
        let root2 = (-b - sqrtDiscriminant) / (2 * a)
        print("The roots are real and different.")
        print("Root 1: \(root1)")
        print("Root 2: \(root2)")
    } else if discriminant == 0 {
        let root = -b / (2 * a)
        print("The roots are real and the same.")
        print("Root: \(root)")
    } else {
        print("There are no roots for this equation.")
    }
}

// Main program
func main() {
    print("Solve the quadratic equation ax^2 + bx + c = 0")

    guard let a = readCoefficient(prompt: "Enter coefficient a:"), a != 0 else {
        print("Coefficient a cannot be zero.")
        return
    }

    guard let b = readCoefficient(prompt: "Enter coefficient b:") else {
        return
    }

    guard let c = readCoefficient(prompt: "Enter coefficient c:") else {
        return
    }

    solveQuadraticEquation(a: a, b: b, c: c)
}

// Run the program
main()
