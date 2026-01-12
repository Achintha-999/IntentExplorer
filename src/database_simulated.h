#ifndef DATABASE_SIMULATED_H
#define DATABASE_SIMULATED_H

#include <string>
#include <map>
#include <vector>

class DatabaseSimulated {
private:
   
    std::map<std::string, std::string> users;  
    std::map<std::string, int> globalScores;   
    std::map<std::string, std::map<std::string, int>> gameScores; 
    
public:
    DatabaseSimulated();
    
    bool connect();
    void disconnect();
    bool ping();
    
   
    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);
    

    bool submitScore(const std::string& username, const std::string& game, int score);
    
   
    std::string getGlobalLeaderboard(int limit = 10);
    std::string getUserRank(const std::string& username, const std::string& game = "global");
    std::string getTopPlayers(int days = 7, int limit = 10);
    
private:
    std::vector<std::pair<std::string, int>> getSortedScores(const std::string& game = "global");
};

#endif
