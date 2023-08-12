#include <iostream>
#include "../include/Meal.h"

using namespace std;

Meal::Meal(string name, int quantity, vector<Ingredient*> inglist, Stock* s)
    : name(name), quantity(quantity), inglist(inglist) {

    calcPrice();
    count = 0;
}

ostream& operator <<(ostream& out, Meal& i) {
    i.getData();
    return out;
}

istream& operator >>(istream& in, Meal* i) {
    i->setData();
    return in;
}

int Meal::getQuantity() {
    return quantity;
}

string Meal::getName() {
    return name;
}

double Meal::getPrice() {
    return price * orderQuantity;
}

Meal::~Meal() {
}