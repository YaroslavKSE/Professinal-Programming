#include <iostream>
#include <vector>
#include <limits> 

int main() {
    int size;
    std::cout << "Enter the number of elements in the list: ";
    std::cin >> size;

    std::vector<int> numbers(size);
    std::cout << "Enter the elements of the list:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> numbers[i];
    }

    int largestNegative = std::numeric_limits<int>::min(); // Initialize with the smallest possible integer
    bool foundNegative = false;

    for (int number : numbers) {
        if (number < 0) {
            if (!foundNegative || number > largestNegative) {
                largestNegative = number;
                foundNegative = true;
            }
        }
    }

    if (foundNegative) {
        std::cout << "The largest negative number is: " << largestNegative << std::endl;
    } else {
        std::cout << "There are no negative numbers in the list." << std::endl;
    }

    return 0;
}
