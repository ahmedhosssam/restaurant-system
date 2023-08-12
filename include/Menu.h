#ifndef MENU_H
#define MENU_H

#include <unistd.h>

#include "Meal.h"
#include "Stock.h"

using namespace std;

class Menu {
    public:
        Menu(Stock* s);
        void add_meal(Meal* m); 
        void deleteMeal(int i);
        void display_all();
        Meal* getMeal(int n);
        int getMealsNumber();
        void setStock(Stock *s);
        ~Menu();

    private:
        vector<Meal*> meallist;
        Stock* s_ptr;
};

#endif
