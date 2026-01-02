#include "database.h"
#include <iostream>
#include <sstream>

Database::Database(const std::string& host, int port)
    : host(host), port(port), context(nullptr) {}

Database::~Database() {
    disconnect();
}

bool Database::connect(){
    context = redisConnect(host.c_str(), port);
    if(context == nullptr || context->err){
        if(context == nullptr || context -> err){
            std::cerr<<"Connection error: "<< context->errstr <<std::endl;
        }else{
            std::cerr<<"Connection error: : Can't allocate redis context" <<std::endl;
        }
        return false;
    }
    std::cout<<"Connected to Redis server at "<<host<<":"<<port<<std::endl;
    return true;
}

void Database::disconnect(){
    if(context){
        redisFree(context);
        context = nullptr;
    }
}

bool Database::ping(){
    redisReply* replay = (redisReply*)redisCommand(context, "PING");
    if(replay == nullptr){
        std::cerr<<"PING command failed"<<std::endl;
        return false;
    }

    bool success = (replay -> type == REDIS_REPLY_STRING &&
    std::string(replay -> str) == "PONG");
    freeReplyObject(replay);
    return success;
}

std::string Database::executeCommand(const std::string& command){
    redisReply* reply = (redisReply*)redisCommand(context, command.c_str());
    if(reply == nullptr){
        return "Error: Command execution failed";
    }

    std::string result;
    if (reply->type == REDIS_REPLY_STRING) {
        result = reply->str;
    } else if (reply->type == REDIS_REPLY_INTEGER) {
        result = std::to_string(reply->integer);
    } else if (reply->type == REDIS_REPLY_ARRAY) {
        for (size_t i = 0; i < reply->elements; i++) {
            result += std::to_string(i + 1) + ". " + reply->element[i]->str;
            if (i < reply->elements - 1) result += "\n";
        }
    }
    
    freeReplyObject(reply);
    return result;
}

