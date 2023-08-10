#include <vector>

#include "../include/Delivery.h"

Delivery::Delivery(vector<Meal*> mealArr) : Order(mealArr) {
    calcPrice();
}

void Delivery::calcPrice() {
    total_price = 0;
    for (int i = 0; i < int(mealArr.size()); ++i) {
        total_price += mealArr[i]->getPrice();
    }

    total_price += 5; // delivery cost
}

double Delivery::getPrice() {
    return total_price;
}

void Delivery::printReciept() {
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < int(mealArr.size()); ++i) {
        total_price += mealArr[i]->getPrice();
        cout << mealArr[i]->getOrderQuantity() << "\t" << mealArr[i]->getName() << "\t" << "$" << mealArr[i]->getPrice() << endl;
    }

    cout << "Delivery cost \t$5\n";
    cout << "----------------\n";
    cout << "Total Price : $" << total_price << endl;
    cout << "--------------------------------------" << endl;
}

Delivery::~Delivery() {
    //dtor
}
