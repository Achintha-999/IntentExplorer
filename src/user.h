#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;
    int id;
    
public:
    User();
    User(std::string username, std::string password);
    
   
    std::string getUsername() const;
    std::string getPassword() const;
    int getId() const;
    
  
    void setUsername(const std::string& username);
    void setPassword(const std::string& password);
    void setId(int id);
    
   
    bool authenticate(const std::string& password) const;
};

#endif