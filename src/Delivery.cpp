#include <vector>

#include "../include/Delivery.h"

Delivery::Delivery(vector<Meal*> mealArr) : Order(mealArr) {
    total_price += 5; // delivery cost
}

void Delivery::printReciept() {
    int mealArrSize = static_cast<int>(mealArr.size());

    cout << "--------------------------------------" << endl;

    for (int i = 0; i < mealArrSize; ++i) {
        cout << mealArr[i]->getOrderQuantity() << "\t" << mealArr[i]->getName() << "\t" << "$" << mealArr[i]->getOrderPrice() << endl;
    }

    cout << "Delivery cost \t$5\n";
    cout << "----------------\n";
    cout << "Total Price : $" << total_price << endl;
    cout << "--------------------------------------" << endl;
}

Delivery::~Delivery() {
}
