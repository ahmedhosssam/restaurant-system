#include "../include/InRestaurant.h"

InRestaurant::InRestaurant(vector <Meal*> mealArr, int tableId) : Order(mealArr), tableId(tableId) {
    calcPrice();
}

void InRestaurant::calcPrice() {
    total_price = 0;
    int mealArrSize = static_cast<int>(mealArr.size());

    for (int i = 0; i < mealArrSize; ++i) {
        total_price += mealArr[i]->getPrice();
    }
}

double InRestaurant::getPrice() {
    return total_price;
}

void InRestaurant::printReciept() {
    int mealArrSize = static_cast<int>(mealArr.size());

    cout << "--------------------------------------" << endl;

    for (int i = 0; i < mealArrSize; ++i) {
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