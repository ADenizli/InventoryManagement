#include <iostream>

// OWN MODULES
#include "modules/User.h"
#include "modules/Product.h"
#include "modules/Inventory.h"

class Core {
    private:
    UserModule userModule;
    ProductModule productModule;
    InventoryModule inventoryModule;


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
        this->inventoryModule.Initialize(this->productModule);
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
        
        bool response = this->userModule.Login({username, password});

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
        
        bool response = this->userModule.NewRegistration({username, password});

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
        int subMenu;
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
        std::string userInput;

        switch (selection)
        {
        case 1:
            {std::cout << "=======CREATE PRODUCT========" << std::endl;
            std::cout << "Enter an title for new product creation!" << std::endl;
            std::cout << "=============================" << std::endl;
            std::cin >> userInput;
            bool response = this->productModule.CreateProduct(Product {userInput});
            if (response)
            {
                std::cout << "=============================" << std::endl;
                std::cout << "Creation successfully, returning to the menu!" << std::endl;
                std::cout << "=============================" << std::endl;
            } else {
                std::cout << "=============================" << std::endl;
                std::cout << "You have reached maximum capacity, returning to the menu!" << std::endl;
                std::cout << "=============================" << std::endl;
            }
            this->MenuCLI();
            break;}
        
        case 2:
            {std::cout << "=======PRODUCT LIST========" << std::endl;
            this->productModule.ListOfProducts();
            std::cout << "=============================" << std::endl;
            std::cout << "To edit product write index, to return menu write 99" << std::endl;
            std::cout << "=============================" << std::endl;
            std::cin >> subMenu;
            switch (subMenu)
            {
            case 99:
                this->MenuCLI();
                break;
            
            default:
                while (!(0 <= subMenu && subMenu <= 9))
                {
                    std::cout << "Entered undefined index! Type defined one!" << std::endl;
                    std::cin >> subMenu;
                    if (subMenu == 99)
                    {
                        this->MenuCLI();
                    }
                    
                }
                std::string editedProduct;
                std::cout << "=============================" << std::endl;
                std::cout << "Enter New Product Title!" << std::endl;
                std::cout << "=============================" << std::endl;
                std::cin >> editedProduct;
                bool response = this->productModule.EditProduct(subMenu, Product { editedProduct});
                if (response)
                {
                    std::cout << "=============================" << std::endl;
                    std::cout << "Product Updated Successfully!" << std::endl;
                    std::cout << "Returning to the menu!" << std::endl;
                    std::cout << "============================  =" << std::endl;
                    this->MenuCLI();
                } else {
                    std::cout << "============ !!! =============" << std::endl;
                    std::cout << "Something went wrong!" << std::endl;
                    std::cout << "Returning to the menu!" << std::endl;
                    std::cout << "============ !!! =============" << std::endl;
                    this->MenuCLI(); 
                }
                break;
            };
            break;}
        
        case 3:
            {std::cout << "=======PRODUCT LIST========" << std::endl;
            this->productModule.ListOfProducts();
            std::cout << "=============================" << std::endl;
            std::cout << "To new incoming product write index, to return menu write 99" << std::endl;
            std::cout << "=============================" << std::endl;
            std::cin >> subMenu;
            switch (subMenu)
            {
                case 99:
                    {this->MenuCLI();
                    break;
                }
                default:
                    {while (!(0 <= subMenu && subMenu <= 9))
                    {
                        std::cout << "Entered undefined index! Type defined one!" << std::endl;
                        std::cin >> subMenu;
                        if (subMenu == 99)
                        {
                            this->MenuCLI();
                        }
                        
                    }
                    int enteredAmount;
                    std::cout << "=============================" << std::endl;
                    std::cout << "Enter amount of incoming!" << std::endl;
                    std::cout << "============================  =" << std::endl;
                    std::cin >> enteredAmount;
                    bool response = this->inventoryModule.InventoryAction(InventoryActionStruct {Inbound, subMenu, enteredAmount });
                    if (response)
                    {
                        std::cout << "=============================" << std::endl;
                        std::cout << "Incoming setted successfully!" << std::endl;
                        std::cout << "Returning to the menu!" << std::endl;
                        std::cout << "============================  =" << std::endl;
                        this->MenuCLI();
                    } else {
                        std::cout << "============ !!! =============" << std::endl;
                        std::cout << "Overflow in capacity!" << std::endl;
                        std::cout << "Returning to the menu!" << std::endl;
                        std::cout << "============ !!! =============" << std::endl;
                        this->MenuCLI(); 
                    }
                    break;}
            };
            break;}
        
        case 4:
            {std::cout << "=======PRODUCT LIST========" << std::endl;
            this->productModule.ListOfProducts();
            std::cout << "=============================" << std::endl;
            std::cout << "To new outbound product write index, to return menu write 99" << std::endl;
            std::cout << "=============================" << std::endl;
            std::cin >> subMenu;
            switch (subMenu)
            {
                case 99:
                    this->MenuCLI();
                    break;
                
                default:
                    while (!(0 <= subMenu && subMenu <= 9))
                    {
                        std::cout << "Entered undefined index! Type defined one!" << std::endl;
                        std::cin >> subMenu;
                        if (subMenu == 99)
                        {
                            this->MenuCLI();
                        }
                        
                    }
                    int enteredAmount;
                    std::cout << "=============================" << std::endl;
                    std::cout << "Enter amount of outbound!" << std::endl;
                    std::cout << "============================  =" << std::endl;
                    std::cin >> enteredAmount;
                    bool response = this->inventoryModule.InventoryAction(InventoryActionStruct { Outbound, subMenu, enteredAmount });
                    if (response)
                    {
                        std::cout << "=============================" << std::endl;
                        std::cout << "outbound setted successfully!" << std::endl;
                        std::cout << "Returning to the menu!" << std::endl;
                        std::cout << "=============================" << std::endl;
                        this->MenuCLI();
                    } else {
                        std::cout << "============ !!! =============" << std::endl;
                        std::cout << "You set a value that higher than capacity!" << std::endl;
                        std::cout << "Returning to the menu!" << std::endl;
                        std::cout << "============ !!! =============" << std::endl;
                        this->MenuCLI(); 
                    }
                    break;
            }
            break;}
        
        case 5:
           { std::cout << "=============================" << std::endl;
            std::cout << "===== INVENTORY STATUS ======" << std::endl;
            std::cout << "=============================" << std::endl;
            this->inventoryModule.ReturnInventory();
            this->MenuCLI();
            break;}
        default:
            break;
        }
    };
};

int main() {
    Core core;
    core.Ignition();
    core.LandingCLI();
    return 0;
}