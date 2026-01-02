#ifndef DATABASE_H
#define DATABASE_H

#include <hiredis/hiredis.h>
#include <string>

class Database {
private:
    redisContext* context;
    std::string host;
    int port;

public:
    Database(const std::string& host ="127.0.0.1", int port = 6379);    
    ~Database();

    bool connect();
    void disconnect();


    std::string executeCommand(const std::string& command);
    bool ping();

    bool registerUser(const std::string& username, const std::string& password);
    bool loginUser(const std::string& username, const std::string& password);

    bool submitScore(const std::string& username, const std::string& game, int score);

    std::string getGlobalLeaderboard(int limit = 10);
    std::string getUserRank(const std::string& username, const std::string& game = "global");
    std::string getTopPlayers(int days = 7, int limit = 10);
};

#endif