#include "../include/InRestaurant.h"

InRestaurant::InRestaurant(Meal** mealArr, int mealCount, int tableId) : Order(mealArr, mealCount), tableId(tableId) {
    calcPrice();
}

void InRestaurant::calcPrice() {
    total_price = 0;

    for (int i = 0; i < mealCount; ++i) {
        total_price += mealArr[i]->getPrice();
    }
}

double InRestaurant::getPrice() {
    return total_price;
}

void InRestaurant::printReciept() {
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < mealCount; ++i)
    {
        total_price += mealArr[i]->getPrice();
        cout << mealArr[i]->getOrderQuantity() << "\t" << mealArr[i]->getName() << "\t" << "$" << mealArr[i]->getPrice() << endl;
    }
    cout << "----------------\n";
    cout << "Table num: " << tableId << endl;
    cout << "----------------\n";
    calcPrice();
    cout << "Total Price : $" << total_price << endl;
    cout << "--------------------------------------" << endl;
}

InRestaurant::~InRestaurant() {
}
