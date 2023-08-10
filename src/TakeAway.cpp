#include <iostream>
#include <vector>

#include "../include/TakeAway.h"
#include "../include/Order.h"
#include "../include/Meal.h"

using namespace std;

TakeAway::TakeAway(Meal** mealArr, int mealCount) : Order(mealArr, mealCount)
{
    calcPrice();
}

void TakeAway::calcPrice()
{
    total_price = 0;
    for (int i = 0; i < mealCount; ++i)
    {
        total_price += mealArr[i]->getPrice();
    }
}

double TakeAway::getPrice()
{
    return total_price;
}

void TakeAway::printReciept()
{
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < mealCount; ++i)
    {
        total_price += mealArr[i]->getPrice();
        cout << mealArr[i]->getOrderQuantity() << "\t" << mealArr[i]->getName() << "\t" << "$" << mealArr[i]->getPrice() << endl;
    }
    cout << "----------------\n";
    calcPrice();
    cout << "Total Price : $" << total_price << endl;
    cout << "--------------------------------------" << endl;
}
