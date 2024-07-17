#pragma once
#include "Team.hpp"
#include <vector>
#include <functional>

class TeamSorter {
public:
    TeamSorter();
    void sortTeams(std::vector<Team>& teams) const;

private:
    using CompareFunc = std::function<bool(const Team&, const Team&)>;
    std::vector<CompareFunc> criteria;

    bool compareTeams(const Team& a, const Team& b) const;
};
