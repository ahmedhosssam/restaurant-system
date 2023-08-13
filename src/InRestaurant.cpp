#include "../include/InRestaurant.h"

InRestaurant::InRestaurant(vector <Meal*> mealArr, int tableId) : Order(mealArr), tableId(tableId) {
}

void InRestaurant::printReciept() {
    total_price = 0;
    int mealArrSize = static_cast<int>(mealArr.size());

    cout << "--------------------------------------" << endl;

    for (int i = 0; i < mealArrSize; ++i) {
        total_price += mealArr[i]->getOrderPrice();
        cout << mealArr[i]->getOrderQuantity() << "\t" << mealArr[i]->getName() << "\t" << "$" << mealArr[i]->getOrderPrice() << endl;
    }

    cout << "----------------\n";
    cout << "Table num: " << tableId << endl;
    cout << "----------------\n";

    cout << "Total Price : $" << total_price << endl;
    cout << "--------------------------------------" << endl;
}

InRestaurant::~InRestaurant() {
}