#pragma once
#include <string>
#include <vector>
#include <ranges>

class Team {
public:
    Team(const std::string& name);

    void addMatchResult(int goalsScored, int goalsConceded, int yellowCards, int redCards, double topHeight);

    double getTotalPoints() const;
    double getTotalTopHeight() const;
    int getGoalDifference() const;
    int getTotalGoalsScored() const;
    int getTotalYellowCards() const;
    int getTotalRedCards() const;
    const std::string& getName() const;

private:
    std::string name;
    double points;
    double totalTopHeight;
    int totalGoalsScored;
    int totalGoalsConceded;
    int yellowCards;
    int redCards;
};
