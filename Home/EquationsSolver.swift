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
// and to print the results... but why prints are the part of this function?
// It is better to have a single responsibility for the function
// At the moment this function has side effects
// that are not mentioned neither in comment to it nor in function name
//  solveQuadraticEquationAndPrintRoots
// It is better to have business logic related to calcultions seprately
// and return result while another layer should be responsible
// for further processing or display of the result
func solveQuadraticEquation(a: Double, b: Double, c: Double) {
    let discriminant = b * b - 4 * a * c
    let sqrtDiscriminant = discriminant.squareRoot() // good move, 1/(2*a) can be also cached:-)

    // consider the following rearrangement as an option
    if discriminant < 0 {
        print("There are no roots for this equation.")
        return;
    }

    if discriminant == 0 {
        let root = -b / (2 * a)
        print("The roots are real and the same.")
        print("Root: \(root)")
        return;
    }

    let root1 = (-b + sqrtDiscriminant) / (2 * a)
    let root2 = (-b - sqrtDiscriminant) / (2 * a)
    print("The roots are real and different.")
    print("Root 1: \(root1)")
    print("Root 2: \(root2)")
}

// Main program
func main() {
    print("Solve the quadratic equation ax^2 + bx + c = 0")

    // Copy paste that can be eliminated readCoefficient(name: "a") and prompt can be generated inside the function
    // While another possible improvement is to inform the user
    // that we are not ok with 0 value - it will make your program more user friendly
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
