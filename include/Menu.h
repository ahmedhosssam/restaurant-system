#ifndef MENU_H
#define MENU_H

#include <unistd.h>

#include "Meal.h"
#include "Meal.h"
#include "Stock.h"

using namespace std;

class menu {
    public:
        menu();
        void add_meal(stock*);
        void add_meal(Meal m);
        void updateMealPrice();
        void deleteMeal();
        void display_all();
        int getMealsNumber();
        Meal* getMeal(int n);
        virtual ~menu();

    protected:

    private:
        int m_mealCount , m_MealSize;
        Meal *mealList;
};

#endif // MENU_H
