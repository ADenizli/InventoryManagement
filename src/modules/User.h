// UserModule.h
#pragma once

#include <iostream>

struct User {
    std::string username;
    std::string password;
};

class UserModule {
private:
    User users[10];
    int totalUserCount = 0;
    int maxUserCount = 10;
    bool isLoggedIn = false;

public:
    bool NewRegistration(User user);
    bool Login(User user);
    bool isAuthorized();
};
