#include "user.h"
#include <iostream>

User::User() : username(""), password(""), id(0) {}

User::User(std::string username, std::string password)
    : username(username), password(password), id(0) {}

std::string User::getUsername() const {
    return username;
}

std::string User::getPassword() const {
    return password;
}

int User::getId() const {
    return id;
}

void User::setUsername(const std::string& username) {
    this->username = username;
}

void User::setPassword(const std::string& password) {
    this->password = password;
}
void User::setId(int id) {
    this->id = id;
}

bool User::authenticate(const std::string&password) const{
    return this->password == password;
}

