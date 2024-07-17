#include "Tournament.hpp"
#include "MatchInput.hpp"
#include <iostream>
#include <string>
#include <print>

int main() {
    Tournament tournament;
    MatchInput matchInput;
    std::string name;

    // Prompting for team names
    for (int i = 0; i < 4; ++i) {
        std::println("Enter team {} name: ", i + 1);
        std::getline(std::cin, name);
        tournament.addTeam(name);
    }

    const auto& teamNames = tournament.getTeamNames();
    std::vector<std::pair<int, int>> matches = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};

    int goals1, goals2, yellow1, yellow2, red1, red2;
    double height1, height2;

    // Prompting for match details
    for (size_t i = 0; i < matches.size(); ++i) {
        const auto& [team1Index, team2Index] = matches[i];
        const std::string& team1 = teamNames[team1Index];
        const std::string& team2 = teamNames[team2Index];

        std::println("Enter match {} details", i + 1);
        matchInput.getMatchDetails(team1, team2, goals1, goals2, yellow1, yellow2, red1, red2, height1, height2);
        tournament.addMatchResult(team1, team2, goals1, goals2, yellow1, yellow2, red1, red2, height1, height2);
    }

    std::println("Tournament results:");
    tournament.printResults();

    return 0;
}
