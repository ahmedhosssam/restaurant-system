#include <iostream>
#include <string>
#include "Order.h"
#include "Meal.h"

using namespace std;

Order::Order(Meal** mealArr, int mealCount) : mealArr(mealArr), mealCount(mealCount)
{
    total_price = 0;
}

void Order::calcPrice()
{
}

double Order::getPrice()
{
    return total_price;
}

void Order::printReciept()
{
}

Order::~Order()
{
    // Clean up the dynamic array
    for (int i = 0; i < mealCount; i++)
    {
        delete mealArr[i];
    }
    delete[] mealArr;
}
