import Foundation
import BusinessLogic
import DataAccess

public class ConsoleInterface {
    private let businessLogic: BusinessLogicFacade
    
    public init(businessLogic: BusinessLogicFacade) {
        self.businessLogic = businessLogic
    }
    
    public func start() {
        print("Welcome to our Handmade Clothes Store!")
        
        while true {
            printMainMenu()
            
            guard let choice = readLine(), let option = Int(choice) else {
                print("Invalid input. Please try again.")
                continue
            }
            
            switch option {
            case 1:
                handleUserManagement()
            case 2:
                handleProductCatalog()
            case 3:
                print("Thank you for using our store. Goodbye!")
                return
            default:
                print("Invalid option. Please try again.")
            }
        }
    }
    
    private func printMainMenu() {
        print("\nMain Menu:")
        print("1. User Management")
        print("2. Product Catalog")
        print("3. Exit")
        print("Please enter your choice (1-3):")
    }
    
    private func handleUserManagement() {
        while true {
            printUserMenu()
            
            guard let choice = readLine(), let option = Int(choice) else {
                print("Invalid input. Please try again.")
                continue
            }
            
            switch option {
            case 1:
                registerUser()
            case 2:
                loginUser()
            case 3:
                registerUserWithSocialMedia()
            case 4:
                recoverPassword()
            case 5:
                return
            default:
                print("Invalid option. Please try again.")
            }
        }
    }
    
    private func printUserMenu() {
        print("\nUser Management:")
        print("1. Register new user")
        print("2. Login")
        print("3. Register with social media")
        print("4. Recover password")
        print("5. Back to main menu")
        print("Please enter your choice (1-5):")
    }
    
    private func registerUser() {
        print("Enter email:")
        guard let email = readLine(), !email.isEmpty else {
            print("Invalid email.")
            return
        }
        
        print("Enter password:")
        guard let password = readLine(), !password.isEmpty else {
            print("Invalid password.")
            return
        }
        
        do {
            try businessLogic.registerUser(email: email, password: password)
            print("User registered successfully!")
        } catch {
            print("Error registering user: \(error.localizedDescription)")
        }
    }
    
    private func loginUser() {
        print("Enter email:")
        guard let email = readLine(), !email.isEmpty else {
            print("Invalid email.")
            return
        }
        
        print("Enter password:")
        guard let password = readLine(), !password.isEmpty else {
            print("Invalid password.")
            return
        }
        
        do {
            let user = try businessLogic.loginUser(email: email, password: password)
            print("Welcome, \(user.email)!")
        } catch {
            print("Error logging in: \(error.localizedDescription)")
        }
    }
    
    private func registerUserWithSocialMedia() {
        print("Enter social media account:")
        guard let account = readLine(), !account.isEmpty else {
            print("Invalid social media account.")
            return
        }
        
        do {
            try businessLogic.registerUserWithSocialMedia(socialMediaAccount: account)
            print("User registered successfully with social media account!")
        } catch {
            print("Error registering user: \(error.localizedDescription)")
        }
    }
    
    private func recoverPassword() {
        print("Enter email:")
        guard let email = readLine(), !email.isEmpty else {
            print("Invalid email.")
            return
        }
        
        do {
            try businessLogic.recoverPassword(email: email)
            print("Password recovery initiated. Please check your email.")
        } catch {
            print("Error recovering password: \(error.localizedDescription)")
        }
    }
    
    private func handleProductCatalog() {
        while true {
            printProductMenu()
            
            guard let choice = readLine(), let option = Int(choice) else {
                print("Invalid input. Please try again.")
                continue
            }
            
            switch option {
            case 1:
                browseCatalog()
            case 2:
                filterBySize()
            case 3:
                searchProducts()
            case 4:
                createProduct()
            case 5:
                return
            default:
                print("Invalid option. Please try again.")
            }
        }
    }
    
    private func printProductMenu() {
        print("\nProduct Catalog:")
        print("1. Browse catalog")
        print("2. Filter by size")
        print("3. Search products")
        print("4. Create new product")
        print("5. Back to main menu")
        print("Please enter your choice (1-5):")
    }
    
    private func browseCatalog() {
        print("Enter category (or press Enter for all products):")
        let category = readLine() ?? ""
        
        let products = category.isEmpty ? businessLogic.getAllProducts() : businessLogic.getProductsByCategory(category)
        displayProducts(products)
    }
    
    private func filterBySize() {
        print("Enter size:")
        guard let size = readLine(), !size.isEmpty else {
            print("Invalid size.")
            return
        }
        
        let products = businessLogic.getProductsBySize(size)
        displayProducts(products)
    }
    
    private func searchProducts() {
        print("Enter search keyword:")
        guard let keyword = readLine(), !keyword.isEmpty else {
            print("Invalid keyword.")
            return
        }
        
        let products = businessLogic.searchProducts(keyword: keyword)
        displayProducts(products)
    }
    
    private func displayProducts(_ products: [Product]) {
        if products.isEmpty {
            print("No products found.")
        } else {
            print("\nFound \(products.count) product(s):")
            for (index, product) in products.enumerated() {
                print("\(index + 1). \(product.name) - Category: \(product.category), Size: \(product.size)")
                print("   Description: \(product.description)")
                print()
            }
        }
    }
    private func createProduct() {
        print("Enter product name:")
        guard let name = readLine(), !name.isEmpty else {
            print("Invalid name.")
            return
        }

        print("Enter product category:")
        guard let category = readLine(), !category.isEmpty else {
            print("Invalid category.")
            return
        }

        print("Enter product size:")
        guard let size = readLine(), !size.isEmpty else {
            print("Invalid size.")
            return
        }

        print("Enter product description:")
        guard let description = readLine(), !description.isEmpty else {
            print("Invalid description.")
            return
        }

        do {
            let newProduct = try businessLogic.createProduct(name: name, category: category, size: size, description: description)
            print("Product created successfully!")
            print("New product details:")
            print("Name: \(newProduct.name)")
            print("Category: \(newProduct.category)")
            print("Size: \(newProduct.size)")
            print("Description: \(newProduct.description)")
        } catch {
            print("Error creating product: \(error.localizedDescription)")
        }
    }
}