#include "MatchInput.hpp"
#include <iostream>
#include <print>

void MatchInput::getMatchDetails(const std::string& team1, const std::string& team2, int& goals1, int& goals2, int& yellow1, int& yellow2, int& red1, int& red2, double& height1, double& height2) const {
    std::println("Match between {} and {}", team1, team2);
    std::println("Goals by {}: ", team1);
    std::cin >> goals1;
    std::println("Goals by {}: ", team2);
    std::cin >> goals2;
    std::println("Yellow cards for {}: ", team1);
    std::cin >> yellow1;
    std::println("Yellow cards for {}: ", team2);
    std::cin >> yellow2;
    std::println("Red cards for {}: ", team1);
    std::cin >> red1;
    std::println("Red cards for {}: ", team2);
    std::cin >> red2;
    std::println("Top height reached by {}: ", team1);
    std::cin >> height1;
    std::println("Top height reached by {}: ", team2);
    std::cin >> height2;
}
