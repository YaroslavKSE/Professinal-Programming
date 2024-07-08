func main() {
    let milk = Milk(coefficient: 1.5, basePrice: 2.0)
    let cookies = Cookies(coefficient: 2.0, basePrice: 3.0)
    let pineapple = Pineapple(coefficient: 1.8, basePrice: 4.0)

    let presenter = PricePresenter<Int>()

    presenter.printTotalPrice(milk, cookies, priority: 2)
    presenter.printTotalPrice(milk, pineapple, priority: 2)
    presenter.printTotalPrice(cookies, pineapple, priority: 2)
}

main()
