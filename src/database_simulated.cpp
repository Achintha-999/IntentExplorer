#include "database_simulated.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>

DatabaseSimulated::DatabaseSimulated() {
    // Constructor
}

bool DatabaseSimulated::connect() {
    std::cout << "Connected to simulated database!" << std::endl;
    return true;
}

void DatabaseSimulated::disconnect() {
    std::cout << "Disconnected from simulated database!" << std::endl;
}

bool DatabaseSimulated::ping() {
    return true;
}

bool DatabaseSimulated::registerUser(const std::string& username, const std::string& password) {
    // Check if user exists
    if (users.find(username) != users.end()) {
        std::cout << "User already exists!" << std::endl;
        return false;
    }
    
    // Register new user
    users[username] = password;
    globalScores[username] = 0;  // Initialize with 0 score
    
    std::cout << "User '" << username << "' registered successfully!" << std::endl;
    return true;
}

bool DatabaseSimulated::loginUser(const std::string& username, const std::string& password) {
    auto it = users.find(username);
    if (it == users.end()) {
        std::cout << "User not found!" << std::endl;
        return false;
    }
    
    if (it->second == password) {
        std::cout << "Login successful! Welcome " << username << "!" << std::endl;
        return true;
    } else {
        std::cout << "Incorrect password!" << std::endl;
        return false;
    }
}

bool DatabaseSimulated::submitScore(const std::string& username, const std::string& game, int score) {
    // Update global score (keep highest)
    if (globalScores.find(username) == globalScores.end() || globalScores[username] < score) {
        globalScores[username] = score;
    }
    
    // Update game-specific score
    if (gameScores[game].find(username) == gameScores[game].end() || gameScores[game][username] < score) {
        gameScores[game][username] = score;
    }
    
    std::cout << "Score submitted: " << username << " scored " << score 
              << " in " << game << std::endl;
    return true;
}

std::vector<std::pair<std::string, int>> DatabaseSimulated::getSortedScores(const std::string& game) {
    std::vector<std::pair<std::string, int>> sortedScores;
    
    if (game == "global") {
        // Copy global scores to vector
        for (const auto& entry : globalScores) {
            if (entry.second > 0) {  // Only include users with scores
                sortedScores.push_back(entry);
            }
        }
    } else {
        // Copy game-specific scores to vector
        auto gameIt = gameScores.find(game);
        if (gameIt != gameScores.end()) {
            for (const auto& entry : gameIt->second) {
                sortedScores.push_back(entry);
            }
        }
    }
    
    // Sort by score (descending)
    std::sort(sortedScores.begin(), sortedScores.end(),
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });
    
    return sortedScores;
}

std::string DatabaseSimulated::getGlobalLeaderboard(int limit) {
    auto sortedScores = getSortedScores("global");
    
    std::stringstream result;
    result << "=== Global Leaderboard ===\n";
    
    int rank = 1;
    for (const auto& entry : sortedScores) {
        if (rank > limit) break;
        result << rank << ". " << entry.first << " - " << entry.second << "\n";
        rank++;
    }
    
    if (sortedScores.empty()) {
        result << "No scores yet!\n";
    }
    
    return result.str();
}

std::string DatabaseSimulated::getUserRank(const std::string& username, const std::string& game) {
    auto sortedScores = getSortedScores(game);
    
    for (size_t i = 0; i < sortedScores.size(); i++) {
        if (sortedScores[i].first == username) {
            int rank = i + 1;
            int score = sortedScores[i].second;
            return username + "'s rank in " + game + ": " + 
                   std::to_string(rank) + " (Score: " + std::to_string(score) + ")";
        }
    }
    
    return username + " not found in " + game + " leaderboard";
}

std::string DatabaseSimulated::getTopPlayers(int days, int limit) {
    // For simulation, just return current leaderboard
    return getGlobalLeaderboard(limit);
}