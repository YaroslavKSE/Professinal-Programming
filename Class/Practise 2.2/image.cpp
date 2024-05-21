#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <tuple>
#include <ranges>
#include <print>
#include <ranges>
#include <string_view>

namespace {
    constexpr int IMAGE_SIZE = 16;
}

struct Color {
    int r, g, b;

    bool operator==(const Color& other) const {
        return r == other.r && g == other.g && b == other.b;
    }

    bool isValid() const {
        return (r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255);
    }
};

using Image = std::array<std::array<Color, IMAGE_SIZE>, IMAGE_SIZE>;

bool readRow(std::istringstream& lineStream, std::array<Color, IMAGE_SIZE>& row) {
    for (auto& pixel : row) {
        char delimiter;
        if (!(lineStream >> pixel.r >> delimiter >> pixel.g >> delimiter >> pixel.b) || delimiter != ',') {
            return false;
        }
    }
    return true;
}

bool readImage(const std::string& inputFilename, Image& image) {
    std::ifstream file(inputFilename);
    if (!file.is_open()) {
        std::println("Failed to open file: {}", inputFilename);
        return false;
    }

    std::string line;
    for (auto& row : image) {
        if (!std::getline(file, line)) {
            std::println("Invalid input format: not enough lines.");
            return false;
        }

        std::istringstream lineStream(line);
        if (!readRow(lineStream, row)) {
            std::println("Invalid input pixel format in row.");
            return false;
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

void applyFavoriteColor(Image& image, const Color& favoriteColor) {
    for (int i = 0; i < IMAGE_SIZE; ++i) {
        for (int j = 0; j < IMAGE_SIZE; ++j) {
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
    std::cin >> favoriteColor.r >> favoriteColor.g >> favoriteColor.b;

    if (!favoriteColor.isValid()) {
        std::println("Invalid color input. Each component should be between 0 and 255.");
        return 1;
    }

    std::println("Enter output file name: ");
    std::cin >> outputFilename;

    Image image;
    if (!readImage(inputFilename, image)) {
        return 1;
    }

    applyFavoriteColor(image, favoriteColor);

    writeImage(outputFilename, image);

    std::println("Image processing complete. Output written to {}.", outputFilename);

    return 0;
}
