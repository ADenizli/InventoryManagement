#pragma once
#include <iostream>

struct Product {
    std::string title;
};

class ProductModule {
    private:
        Product products[10];
        int totalProductCount = 0;
        int maxProductCount = 10;

    public:
        bool CreateProduct(Product product) ;

        bool EditProduct(int index, Product product) ;

        void ListOfProducts();
};