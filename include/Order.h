#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <vector>

#include "Meal.h"

using namespace std;

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
        vector<Meal*> mealArr;
};

#endif 
