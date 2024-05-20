#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <print>
#include <ranges>
#include <sstream>

using namespace std;

const string FILENAME = "user_stats.txt";

struct UserStat {
    string name;
    int count;

    UserStat(const string& name = "", int count = 0) : name(name), count(count) {}

    friend ostream& operator<<(ostream& os, const UserStat& stat) {
        os << stat.name << " " << stat.count;
        return os;
    }

    friend istream& operator>>(istream& is, UserStat& stat) {
        is >> stat.name >> stat.count;
        return is;
    }
};

class UserStatsManager {
private:
    unordered_map<string, UserStat> userStats;

public:
    UserStatsManager() {
        loadUserStats();
    }

    void loadUserStats() {
        ifstream file(FILENAME);

        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                istringstream iss(line);
                UserStat stat;
                iss >> stat;
                userStats[stat.name] = stat;
            }
            file.close();
        }
    }

    void saveUserStats() const {
        ofstream file(FILENAME, ios::trunc);

        if (file.is_open()) {
            for (const auto& entry : userStats | views::values) {
                file << entry << endl;
            }
            file.close();
        }
    }

    void greetUser(const string& name) {
        if (name == "bread") {
            userStats.clear();
            println("All user history has been exterminated!");
            return;
        }

        if (userStats.find(name) == userStats.end()) {
            println("Welcome, {}!", name);
            userStats[name] = UserStat(name, 1);
        } else {
            userStats[name].count++;
            println("Hello again (x{}), {}!", userStats[name].count, name);
        }
    }

    void resetUserStats(const string& name) {
        userStats.erase(name);
        println("Statistics for {} have been reset.", name);
    }

    unordered_map<string, UserStat>& getUserStats() {
        return userStats;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        println("Usage: {} <name> [delete]", argv[0]);
        return 1;
    }

    string name = argv[1];
    bool deleteStats = (argc == 3 && string(argv[2]) == "delete");

    UserStatsManager manager;

    if (deleteStats) {
        manager.resetUserStats(name);
    } else {
        manager.greetUser(name);
    }

    manager.saveUserStats();

    return 0;
}
