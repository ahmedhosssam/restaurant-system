#include <iostream>
#include <vector>
#include <unistd.h>

#include "Ingredient.h"

using namespace std;
#ifndef STOCK_H
#define STOCK_H


class Stock {
    public:
        Stock();
        void add_ingredient();
        void add_ingredient(Ingredient* ing);
        void update_ingredient_quantity();
        void update_ingredient_price();
        void delete_ingredient();
        void display_all();
        int returnIngNum();
        Ingredient* search_ing(int id);
        virtual ~Stock();

    private:
        int m_ingCount;
        vector<Ingredient*> ingList;
};

#endif 
