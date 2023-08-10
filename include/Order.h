#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
#include "Meal.h"

using namespace std;

class Order
{
public:
    Order();
    virtual ~Order();
    Order(Meal** mealArr, int mealCount);
    virtual void calcPrice();
    virtual double getPrice();
    virtual void printReciept();

protected:
    int id;
    double total_price;
    Meal** mealArr;
    int mealCount;

private:
};

#endif // ORDER_H
