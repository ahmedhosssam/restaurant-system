#include "../include/Delivery.h"

Delivery::Delivery(Meal** mealArr, int mealCount) : Order(mealArr, mealCount)
{
    calcPrice();
}

void Delivery::calcPrice()
{
    total_price = 0;
    for (int i = 0; i < mealCount; ++i)
    {
        total_price += mealArr[i]->getPrice();
    }
    total_price += 5; // delivery cost
}

double Delivery::getPrice()
{
    return total_price;
}

void Delivery::printReciept()
{
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < mealCount; ++i)
    {
        total_price += mealArr[i]->getPrice();
        cout << mealArr[i]->getOrderQuantity() << "\t" << mealArr[i]->getName() << "\t" << "$" << mealArr[i]->getPrice() << endl;
    }
    cout << "Delivery cost \t$5\n";
    cout << "----------------\n";
    calcPrice();
    cout << "Total Price : $" << total_price << endl;
    cout << "--------------------------------------" << endl;
}

Delivery::~Delivery()
{
    //dtor
}
