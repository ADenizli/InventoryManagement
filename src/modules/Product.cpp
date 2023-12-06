#include <iostream>
#include "Product.h"

bool ProductModule::CreateProduct(Product product) {
    if (this->maxProductCount == this->totalProductCount)
    {
        return false;
    } else {
        this->products[this->totalProductCount] = product;
        this->totalProductCount = this->totalProductCount + 1;
        return true;
    }   
}

bool ProductModule::EditProduct(int index, Product product) {
    if (index <= 9 && index >= 0)
    {
        this->products[index] = product;
        return true;
    }
    else {
        return false;
    }
}

void ProductModule::ListOfProducts() {
    std::cout << "Index | Title" << std::endl;
    for (size_t i = 0; i < this->totalProductCount; i++)
    {
        std::cout << "ID: " << i << "Product Title: " << products[i].title << std::endl;
    };
}

Product ProductModule::GetProductByIndex(int index) {
    return this->products[index];
}