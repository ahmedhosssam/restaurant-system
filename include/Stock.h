#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <vector>
#include <unistd.h>

#include "Ingredient.h"

using namespace std;

// includes ingredients
class Stock {
    public:
        Stock();
        void add_ingredient();
        void add_ingredient(Ingredient* ing);
        void update_ingredient_quantity();
        void update_ingredient_price();
        void delete_ingredient();
        void display_all();
        int returnIngNum(); // how many ingredients are there
        Ingredient* return_ing(int id);
        ~Stock();

    private:
        int m_ingCount;
        vector<Ingredient*> ingList; // all of ingredients in the stock
};

#endif 
