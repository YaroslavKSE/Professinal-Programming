#pragma once
#include <string>
#include <vector>

class MatchInput {
public:
    void getMatchDetails(const std::string& team1, const std::string& team2, int& goals1, int& goals2, int& yellow1, int& yellow2, int& red1, int& red2, double& height1, double& height2) const;
};
