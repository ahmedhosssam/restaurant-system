#ifndef MENU_H
#define MENU_H

#include <unistd.h>

#include "Meal.h"
#include "Stock.h"

using namespace std;

class Menu {
    public:
        Menu();
        void add_meal(stock*);
        void add_meal(Meal m);
        void updateMealPrice();
        void deleteMeal();
        void display_all();
        int getMealsNumber();
        Meal* getMeal(int n);
        virtual ~Menu();

    private:
        int m_mealCount , m_MealSize;
        Meal *mealList;
};

#endif // MENU_H
