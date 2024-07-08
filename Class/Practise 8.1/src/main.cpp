#include "PricePresenter.hpp"
#include "Milk.hpp"
#include "Cookies.hpp"
#include "Pineapple.hpp"

int main() {
    Milk milk(1.5, 2.0);
    Cookies cookies(2.0, 3.0);
    Pineapple pineapple(1.8, 4.0);

    PricePresenter<2> presenter;

    presenter.printTotalPrice(milk, cookies);
    presenter.printTotalPrice(milk, pineapple);
    presenter.printTotalPrice(cookies, pineapple);

    return 0;
}
