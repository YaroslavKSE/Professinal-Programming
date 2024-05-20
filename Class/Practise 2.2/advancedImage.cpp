#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <tuple>
#include <ranges>
#include <print>

// ANSI escape codes for colors
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string BLUE = "\033[34m";
const std::string RESET = "\033[0m";
const std::string HIGHLIGHT = "\033[43m"; // Yellow background for highlighting

struct Color {
    int r, g, b;

    bool operator==(const Color& other) const {
        return r == other.r && g == other.g && b == other.b;
    }
};

using Image = std::array<std::array<Color, 16>, 16>;

bool readImage(const std::string& inputFilename, Image& image) {
    std::ifstream file(inputFilename);
    if (!file.is_open()) {
        std::println("Failed to open file: {}", inputFilename);
        return false;
    }

    std::string line;
    for (int i = 0; i < 16; ++i) {
        if (!std::getline(file, line)) {
            std::println("Invalid input format: not enough lines.");
            return false;
        }

        std::istringstream lineStream(line);
        for (int j = 0; j < 16; ++j) {
            char delimiter;
            if (!(lineStream >> image[i][j].r >> delimiter >> image[i][j].g >> delimiter >> image[i][j].b) || delimiter != ',') {
                std::println("Invalid input format at line {}, pixel {}.", i + 1, j + 1);
                return false;
            }
        }
    }

    return true;
}

void writeImage(const std::string& outputFilename, const Image& image) {
    std::ofstream file(outputFilename);
    for (const auto& row : image) {
        for (const auto& pixel : row) {
            file << pixel.r << ',' << pixel.g << ',' << pixel.b << ' ';
        }
        file << '\n';
    }
}

void printImage(const Image& image, const Color& favoriteColor) {
    for (const auto& row : image) {
        for (const auto& pixel : row) {
            if (pixel == favoriteColor) {
                std::cout << HIGHLIGHT;
            } else if (pixel.r == 255 && pixel.g == 0 && pixel.b == 0) {
                std::cout << RED;
            } else if (pixel.r == 0 && pixel.g == 255 && pixel.b == 0) {
                std::cout << GREEN;
            } else if (pixel.r == 0 && pixel.g == 0 && pixel.b == 255) {
                std::cout << BLUE;
            }
            std::cout << "■" << RESET;
        }
        std::cout << '\n';
    }
}

void applyFavoriteColor(Image& image, const Color& favoriteColor) {
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            if (image[i][j] == favoriteColor) {
                if (i > 0) {
                    image[i - 1][j] = favoriteColor; // top pixel
                }
                if (j > 0) {
                    image[i][j - 1] = favoriteColor; // left pixel
                }
            }
        }
    }
}

int main() {
    std::string inputFilename, outputFilename;
    Color favoriteColor;

    std::println("Enter input file name: ");
    std::cin >> inputFilename;

    std::println("Enter your favorite color (r g b): ");
    std::println("For red, enter 255 0 0");
    std::println("For green, enter 0 255 0");
    std::println("For blue, enter 0 0 255");
    std::cin >> favoriteColor.r >> favoriteColor.g >> favoriteColor.b;

    std::println("Enter output file name: ");
    std::cin >> outputFilename;

    Image image;
    if (!readImage(inputFilename, image)) {
        return 1;
    }

    std::println("Original Image:");
    printImage(image, favoriteColor);

    applyFavoriteColor(image, favoriteColor);

    std::println("Updated Image:");
    printImage(image, favoriteColor);

    writeImage(outputFilename, image);

    std::println("Image processing complete. Output written to {}.", outputFilename);

    return 0;
}
