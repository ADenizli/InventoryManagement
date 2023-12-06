#pragma once
#include <iostream>

#include "Product.h"

enum InventoryActionTypes {
    Inbound,
    Outbound
};

struct InventoryActionStruct {
    InventoryActionTypes type;
    int amount;
    int productID;
};

class InventoryModule : ProductModule {
    private:
        int InventoryItem[10];
        int overCapacityPerProduct = 500;
        ProductModule productModule;
    public:
    void Initialize(ProductModule productModule);
    bool InventoryAction(InventoryActionStruct inventoryAction);
    void ReturnInventory();  
};