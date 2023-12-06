#include <iostream>
#include "Inventory.h"

bool InventoryModule::InventoryAction(InventoryActionStruct inventoryAction) {
    switch (inventoryAction.type)
    {
    case Outbound:
        if (0 <= inventoryAction.productID <= 9 && this->InventoryItem[inventoryAction.productID] >= inventoryAction.amount)
        {
            this->InventoryItem[inventoryAction.productID] = this->InventoryItem[inventoryAction.productID] - inventoryAction.amount;
            return true;
        };
        return false;
        
        break;
    case Inbound:
        if (0 <= inventoryAction.productID <= 9 && this->InventoryItem[inventoryAction.productID]  + inventoryAction.amount <= this->overCapacityPerProduct)
        {
            this->InventoryItem[inventoryAction.productID] = this->InventoryItem[inventoryAction.productID] + inventoryAction.amount;
            return true;
        };
        return false;
        break;
    
    default:
        return false;
        break;
    }
};

void InventoryModule::ReturnInventory() {
    std::cout << "Inventory Index | Inventory Item | Amount" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        std::cout << i << this->productModule.GetProductByIndex(i).title << this->InventoryItem[i] << std::endl;
    }
};

void InventoryModule::Initialize(ProductModule productModule) {
    this->productModule = productModule;
}