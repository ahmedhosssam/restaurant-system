#include <iostream>
#include <vector>

#include "../include/TakeAway.h"
#include "../include/Order.h"
#include "../include/Meal.h"

using namespace std;

TakeAway::TakeAway(vector<Meal*> mealArr) : Order(mealArr) {
    calcPrice();
}

void TakeAway::calcPrice() {
    total_price = 0;
    int mealArrSize = static_cast<int>(mealArr.size());

    for (int i = 0; i < mealArrSize; ++i) {
        total_price += mealArr[i]->getPrice();
    }
}

double TakeAway::getPrice() {
    return total_price;
}

void TakeAway::printReciept() {
    int mealArrSize = static_cast<int>(mealArr.size());

    cout << "--------------------------------------" << endl;

    for (int i = 0; i < mealArrSize; ++i) {
        total_price += mealArr[i]->getPrice();
        cout << mealArr[i]->getOrderQuantity() << "\t" << mealArr[i]->getName() << "\t" << "$" << mealArr[i]->getPrice() << endl;
    }

    cout << "----------------\n";
    calcPrice();
    cout << "Total Price : $" << total_price << endl;
    cout << "--------------------------------------" << endl;
}