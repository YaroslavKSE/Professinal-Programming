#pragma once
#include "Team.hpp"
#include "TeamSorter.hpp"
#include <vector>

class Tournament {
public:
    void addTeam(const std::string& name);
    void addMatchResult(const std::string& team1, const std::string& team2, int goals1, int goals2, int yellow1, int yellow2, int red1, int red2, double height1, double height2);
    void printResults() const;
    const std::vector<std::string>& getTeamNames() const;

private:
    std::vector<Team> teams;
    TeamSorter teamSorter;

    Team* getTeamByName(const std::string& name);
    void sortTeams(std::vector<Team>& teams) const;
};
