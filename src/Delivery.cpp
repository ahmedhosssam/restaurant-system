#include <vector>

#include "../include/Delivery.h"

Delivery::Delivery(vector<Meal*> mealArr) : Order(mealArr) {
}

void Delivery::calcPrice() {
    Order::calcPrice();

    total_price += 5; // delivery cost
}

double Delivery::getPrice() {
    return total_price;
}

void Delivery::printReciept() {
    total_price = 0;
    int mealArrSize = static_cast<int>(mealArr.size());

    cout << "--------------------------------------" << endl;
    for (int i = 0; i < mealArrSize; ++i) {
        total_price += mealArr[i]->getOrderPrice();
        cout << mealArr[i]->getOrderQuantity() << "\t" << mealArr[i]->getName() << "\t" << "$" << mealArr[i]->getOrderPrice() << endl;
    }
    total_price += 5; // Delivery cost

    cout << "Delivery cost \t$5\n";
    cout << "----------------\n";
    cout << "Total Price : $" << total_price << endl;
    cout << "--------------------------------------" << endl;
}

Delivery::~Delivery() {
}
