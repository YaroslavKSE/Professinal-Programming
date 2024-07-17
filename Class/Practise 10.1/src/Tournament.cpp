#include "Tournament.hpp"
#include <iostream>
#include <ranges>
#include <print>

void Tournament::addTeam(const std::string& name) {
    teams.emplace_back(name);
}

void Tournament::addMatchResult(const std::string& team1, const std::string& team2, int goals1, int goals2, int yellow1, int yellow2, int red1, int red2, double height1, double height2) {
    Team* t1 = getTeamByName(team1);
    Team* t2 = getTeamByName(team2);
    
    if (t1 && t2) {
        t1->addMatchResult(goals1, goals2, yellow1, red1, height1);
        t2->addMatchResult(goals2, goals1, yellow2, red2, height2);
    }
}

Team* Tournament::getTeamByName(const std::string& name) {
    auto it = std::ranges::find_if(teams, [&name](const Team& team) { return team.getName() == name; });
    return it != teams.end() ? &(*it) : nullptr;
}

void Tournament::printResults() const {
    std::vector<Team> sortedTeams = teams;
    sortTeams(sortedTeams);

    for (const auto& team : sortedTeams) {
        std::println("{}: {} points, Goal Diff: {}, Goals Scored: {}, Yellow Cards: {}, Red Cards: {}, Top Height: {}", 
                     team.getName(), team.getTotalPoints(), team.getGoalDifference(), team.getTotalGoalsScored(),
                     team.getTotalYellowCards(), team.getTotalRedCards(), team.getTotalTopHeight());
    }
}

void Tournament::sortTeams(std::vector<Team>& teams) const {
    teamSorter.sortTeams(teams);
}

const std::vector<std::string>& Tournament::getTeamNames() const {
    static std::vector<std::string> names;
    names.clear();
    for (const auto& team : teams) {
        names.push_back(team.getName());
    }
    return names;
}
