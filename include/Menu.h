#include <Meal.h>
#include <unistd.h>
#include "conio.h"
using namespace std;
#ifndef MENU_H
#define MENU_H
#include "Meal.h"
#include "Stock.h"


class menu
{
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
