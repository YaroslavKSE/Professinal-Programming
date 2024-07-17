#include "TeamSorter.hpp"
#include <algorithm>
#include <random>

TeamSorter::TeamSorter() {
    criteria.push_back([](const Team& a, const Team& b) { return a.getTotalPoints() > b.getTotalPoints(); });
    criteria.push_back([](const Team& a, const Team& b) { return a.getTotalTopHeight() > b.getTotalTopHeight(); });
    criteria.push_back([](const Team& a, const Team& b) { return a.getGoalDifference() > b.getGoalDifference(); });
    criteria.push_back([](const Team& a, const Team& b) { return a.getTotalGoalsScored() > b.getTotalGoalsScored(); });
    criteria.push_back([](const Team& a, const Team& b) { return a.getTotalRedCards() < b.getTotalRedCards(); });
    criteria.push_back([](const Team& a, const Team& b) { return a.getTotalYellowCards() < b.getTotalYellowCards(); });
}

void TeamSorter::sortTeams(std::vector<Team>& teams) const {
    auto compare = [this](const Team& a, const Team& b) { return compareTeams(a, b); };
    std::sort(teams.begin(), teams.end(), compare);
}

bool TeamSorter::compareTeams(const Team& a, const Team& b) const {
    for (const auto& criterion : criteria) {
        if (criterion(a, b)) return true;
        if (criterion(b, a)) return false;
    }
    return std::rand() % 2 == 0;
}
