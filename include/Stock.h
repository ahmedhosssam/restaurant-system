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
        void add_ingrediant();
        void update_ingrediant_quantity();
        void update_ingrediant_price();
        void delete_ingrediant();
        void display_all();
        Ingredient* search_ing(int id);
        virtual ~Stock();

    private:
        int m_ingCount;
        vector<Ingredient*> ingList;
};

#endif 
