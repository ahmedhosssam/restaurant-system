#include <iostream>
#include <string>
#include <vector>

#include "../include/Order.h"
#include "../include/Meal.h"

using namespace std;

Order::Order(vector<Meal*> mealArr) : mealArr(mealArr) {
    total_price = 0;
    calcPrice();
}

void Order::calcPrice() {
    int mealArrSize = static_cast<int>(mealArr.size());

    for (int i = 0; i < mealArrSize; ++i) {
        total_price += mealArr[i]->getPrice();
    }
}

double Order::getPrice() {
    return total_price;
}

void Order::printReciept() {
    total_price = 0;
    int mealArrSize = static_cast<int>(mealArr.size());

    cout << "--------------------------------------" << endl;

    for (int i = 0; i < mealArrSize; ++i) {
        total_price += mealArr[i]->getOrderPrice();
        cout << mealArr[i]->getOrderQuantity() << "\t" << mealArr[i]->getName() << "\t" << "$" << mealArr[i]->getOrderPrice() << endl;
    }

    cout << "----------------\n";
    cout << "Total Price : $" << total_price << endl;
    cout << "--------------------------------------" << endl;
}

Order::~Order() {
}
