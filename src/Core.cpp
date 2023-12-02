#include <iostream>

// OWN MODULES
#include "modules/User.h"

class Core {
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

    void Ignition() {
        std::cout << "Welcome to Inventory Module" << std::endl;
        std::cout << "===========================" << std::endl;
    }

    void LandingCLI() {
        int userSelection;
        std::cout << "Please choose a selection below!" << std::endl;
        std::cout << "===========================" << std::endl;
        std::cout << "1 - Login" << std::endl;
        std::cout << "2 - Register" << std::endl;
        std::cout << "3 - Exit!" << std::endl;
        std::cout << "===========================" << std::endl;
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
        std::cout << "===========================" << std::endl;
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
        } else {
            std::cout << "You have reached maximum user count!" << std::endl;
            std::cout << "===========================" << std::endl;
        }
        this->LandingCLI();
    }

    void EditUserCLI() {
            int selection;
            std::cout << "===========================" << std::endl;
            std::cout << "           USERS           " << std::endl;
            std::cout << "===========================" << std::endl;
            userModule.UserList();
            std::cout << "===========================" << std::endl;
            std::cout << "To edit, write an id below; to return to main menu, write 10" << std::endl;
            std::cout << "===========================" << std::endl;
            std::cin >> selection;
            if (selection <= 9 && selection >= 0)
            {
                User selectedUser = userModule.FetchUser(selection);
                std::string newUsername;
                std::string newPassword;
                std::cout << "Active Username: ";
                std::cout << selectedUser.username << std::endl;
                std::cout << "===========================" << std::endl;
                std::cout << "Enter new username" << std::endl;
                std::cout << "===========================" << std::endl;
                std::cin >> newUsername;
                std::cout << "Active password: ";
                std::cout << selectedUser.username << std::endl;
                std::cout << "===========================" << std::endl;
                std::cout << "Enter new password" << std::endl;
                std::cout << "===========================" << std::endl;
                std::cin >> newPassword;
                userModule.EditUser(selection, newUsername, newPassword);
                std::cout << "===========================" << std::endl;
                std::cout << "User edited successfully" << std::endl;
                std::cout << "===========================" << std::endl;
                this->EditUserCLI();
                
                
            } else if(selection == 99) {
                this->MenuCLI();
            } else {
                std::cout << "===========================" << std::endl;
                std::cout << "      Unknown Command      " << std::endl;
                std::cout << "===========================" << std::endl;
                this->EditUserCLI();
            }
            
            

    }

    void MenuCLI() {
        int selection;
        this->CheckAuth();
        std::cout << "===========================" << std::endl;
        std::cout << "Please choose a selection below!" << std::endl;
        std::cout << "===========================" << std::endl;
        std::cout << "1 - Create Product" << std::endl;
        std::cout << "2 - Product List" << std::endl;
        std::cout << "3 - New Entry" << std::endl;
        std::cout << "4 - New Issue" << std::endl;
        std::cout << "5 - Stock Status" << std::endl;
        std::cout << "6 - User List & Edit" << std::endl;
        std::cout << "7 - Logout" << std::endl;
        std::cin >> selection;

        switch (selection)
        {
        case 1:
            /* code */
            break;
        
        case 2:
            /* code */
            break;
        
        case 3:
            /* code */
            break;
        
        case 4:
            /* code */
            break;
        
        case 5:
            /* code */
            break;
        
        case 6:
            break;
        default:
            break;
        }
    }
};

int main() {
    Core core;
    core.Ignition();
    core.LandingCLI();
    return 0;
}