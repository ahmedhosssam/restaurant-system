#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>

#include "Meal.h"

using namespace std;

struct MealToken
{
    Meal* meal;
    int quantity; // quantity of the meal in the order
};


class Order {
    public:
        virtual ~Order();
        Order(vector<Meal*> mealArr);
        virtual void printReciept();
        virtual void calcPrice();
        virtual double getPrice();

    protected:
        int id;
        double total_price;
        vector<MealToken> mealArr;
};

#endif 
