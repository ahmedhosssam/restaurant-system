#include <iostream>
#include <string>
#include <vector>

#include "../include/Order.h"
#include "../include/Meal.h"

using namespace std;

Order::Order(vector<Meal*> mealArr) : mealArr(mealArr) {
    total_price = 0;
}

void Order::calcPrice() {
}

double Order::getPrice() {
    return total_price;
}

void Order::printReciept() {
}

Order::~Order()
{
}
