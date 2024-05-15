#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <print>

using namespace std;

const string FILENAME = "user_stats.txt";

// Function to load user statistics from the file
unordered_map<string, int> loadUserStats() {
    unordered_map<string, int> userStats;
    ifstream file(FILENAME);

    if (file.is_open()) {
        string name;
        int count;
        while (file >> name >> count) {
            userStats[name] = count;
        }
        file.close();
    }

    return userStats;
}

// Function to save user statistics to the file
void saveUserStats(const unordered_map<string, int>& userStats) {
    ofstream file(FILENAME, ios::trunc);

    if (file.is_open()) {
        for (const auto& entry : userStats) {
            file << entry.first << " " << entry.second << endl;
        }
        file.close();
    }
}

// Function to display welcome message and update user statistics
void greetUser(const string& name, unordered_map<string, int>& userStats) {
    if (name == "bread") {
        userStats.clear();
        println("All user history has been exterminated!");
        return;
    }

    if (userStats.find(name) == userStats.end()) {
        println("Welcome, {}!", name);
        userStats[name] = 1;
    } else {
        userStats[name]++;
        println("Hello again(x{}), {}!", userStats[name], name);
    }
}

// Function to reset statistics for a given user
void resetUserStats(const string& name, unordered_map<string, int>& userStats) {
    userStats.erase(name);
    println("Statistics for {} have been reset.", name);

}

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        println("Usage: {} <name> [delete]", argv[0]);
        return 1;
    }

    string name = argv[1];
    bool deleteStats = (argc == 3 && string(argv[2]) == "delete");

    unordered_map<string, int> userStats = loadUserStats();

    if (deleteStats) {
        resetUserStats(name, userStats);
    } else {
        greetUser(name, userStats);
    }

    saveUserStats(userStats);

    return 0;
}
