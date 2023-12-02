#include <iostream>

// OWN MODULES
#include "modules/User.h"

class CoreModule {
    private:
    UserModule userModule;

    public: 
    void CheckAuth() {
        if (!this->userModule.isAuthorized())
        {
            std::cout << "You are not logged in!" << std::endl;
            std::cout << "===========================" << std::endl;
            this->LandingCLI();
        }
    }
    void LandingCLI() {
        int userSelection;
        std::cout << "Welcome to Inventory Module" << std::endl;
        std::cout << "===========================" << std::endl;
        std::cout << "Please choose a selection below!" << std::endl;
        std::cout << "===========================" << std::endl;
        std::cout << "1 - Login" << std::endl;
        std::cout << "2 - Register" << std::endl;
        std::cout << "3 - Exit!" << std::endl;
        std::cin >> userSelection;

        switch (userSelection)
        {
        case 1:
            this->LoginCLI();
            break;
        case 2:
            this->RegisterCLI();
            break;
        case 3:
            std::cout << "Bye bye!" << std::endl;
            break;
        
        default:
            std::cout << "You've entered an unknown command!" << std::endl;
            break;
        };
    };

    void LoginCLI() {
        std::string username,password;
        std::cout << "To login, please enter your username!" << std::endl;
        std::cout << "===========================" << std::endl;
        std::cin >> username;
        std::cout << "To login, please enter your password!" << std::endl;
        std::cout << "===========================" << std::endl;
        std::cin >> password;
        
        bool response = this->userModule.Login({username: username, password: password});

        if (response)
        {
            std::cout << "You are logged in, referring to menu!" << std::endl;
            std::cout << "===========================" << std::endl;
            this->MenuCLI();
        } else {
            std::cout << "You have entered wrong username or password, referring to the landing page!" << std::endl;
            std::cout << "===========================" << std::endl;
            this->LandingCLI();
        }
    }
    void RegisterCLI() {
        std::string username,password;
        std::cout << "To register, please enter an username!" << std::endl;
        std::cout << "===========================" << std::endl;
        std::cin >> username;
        std::cout << "To register, please enter a password!" << std::endl;
        std::cout << "===========================" << std::endl;
        std::cin >> password;
        
        bool response = this->userModule.NewRegistration({username: username, password: password});

        if (response)
        {
            std::cout << "You have registered to system, referring to the landing page!" << std::endl;
            std::cout << "===========================" << std::endl;
            this->MenuCLI();
        } else {
            std::cout << "Something went wrong, referring to the landing page!" << std::endl;
            std::cout << "===========================" << std::endl;
            this->LandingCLI();
        }
    }

    void MenuCLI() {
        this->CheckAuth();
        

        
    }
}

int main() {
    return 0;
}