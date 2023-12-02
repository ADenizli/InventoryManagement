#include <iostream>
#include "User.h"

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
        bool NewRegistration(User user) {
            if(this->totalUserCount != this->maxUserCount) {
                users[this->totalUserCount] = user;
                this->totalUserCount = this->totalUserCount + 1;
            } else {
                std::cout << "You have reached maximum user count!" << std::endl;
            }
        };

        bool Login(User user) {
            for (size_t i = 0; i < totalUserCount; i++)
            {
                if (user.username == users[i].username && user.password == users[i].password)
                {
                    this->isLoggedIn = true;
                    return true;
                }
            }
            return false;
        }

        bool isAuthorized() {
            return isLoggedIn;
        }
};