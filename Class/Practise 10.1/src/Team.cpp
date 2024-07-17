#include "Team.hpp"

Team::Team(const std::string& name) 
    : name(name), points(0), totalTopHeight(0), totalGoalsScored(0), totalGoalsConceded(0), yellowCards(0), redCards(0) {}

void Team::addMatchResult(int goalsScored, int goalsConceded, int yellowCards, int redCards, double topHeight) {
    this->totalGoalsScored += goalsScored;
    this->totalGoalsConceded += goalsConceded;
    this->yellowCards += yellowCards;
    this->redCards += redCards;
    this->totalTopHeight += topHeight;

    if (goalsScored > goalsConceded) {
        points += 3.14;
    } else if (goalsScored == goalsConceded) {
        points += 2.71828;
    } else {
        points -= 0.5;
    }
}

double Team::getTotalPoints() const { return points; }
double Team::getTotalTopHeight() const { return totalTopHeight; }
int Team::getGoalDifference() const { return totalGoalsScored - totalGoalsConceded; }
int Team::getTotalGoalsScored() const { return totalGoalsScored; }
int Team::getTotalYellowCards() const { return yellowCards; }
int Team::getTotalRedCards() const { return redCards; }
const std::string& Team::getName() const { return name; }
