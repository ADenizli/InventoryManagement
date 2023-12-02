#include <iostream>
#include "User.h"

bool UserModule::NewRegistration(User user) {
    if(this->totalUserCount != this->maxUserCount) {
        users[this->totalUserCount] = user;
        this->totalUserCount = this->totalUserCount + 1;
        return true;
    } else {
        std::cout << "You have reached maximum user count!" << std::endl;
        return false;
    }
};

bool UserModule::Login(User user) {
    for (size_t i = 0; i < totalUserCount; i++)
    {
        if (user.username == users[i].username && user.password == users[i].password)
        {
            this->isLoggedIn = true;
            return true;
        }
    }
    return false;
};

bool UserModule::isAuthorized() {
    return this->isLoggedIn;
};

void UserModule::UserList() {
    std::cout << "ID | Username | Password" << std::endl;
    std::cout << "===========================" << std::endl;

    for (size_t i = 0; i < totalUserCount; i++)
    {
        std::cout << i;   
        std::cout << " | ";   
        std::cout << this->users[i].username;
        std::cout << " | ";   
        std::cout << this->users[i].password;
    }
}

User UserModule::FetchUser(int i) {
    return this->users[i];
}

void UserModule::EditUser(int i, std::string newUsername, std::string newPassword) {
    this->users[i].username = newUsername;
    this->users[i].password = newPassword;
}