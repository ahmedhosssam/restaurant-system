#include <iostream>
#include <unistd.h>

#include "Ingredient.h"

using namespace std;
#ifndef STOCK_H
#define STOCK_H


class stock {
    public:
        stock();
        void add_ingrediant();
        void update_ingrediant_quantity();
        void update_ingrediant_price();
        void delete_ingrediant();
        void display_all();
        Ingredient* search_ing(int);
        virtual ~stock();

    private:
        int m_ingCount, m_ingSize;
        Ingredient *ingtList;
};

#endif 
