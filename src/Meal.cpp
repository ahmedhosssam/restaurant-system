#include <iostream>
#include "../include/Meal.h"

using namespace std;

Meal::Meal(Stock* a) {
    z = a;
}

Meal::Meal() {
}

Meal::Meal(string name, int quantity, vector<Ingredient*> inglist)
    : name(name), quantity(quantity), inglist(inglist) {

    calcPrice();
    count = 0;
}

void Meal::setData() {
    
}

void Meal::calcPrice() {
    
}

void Meal::getData() {
   
}

void Meal::print_name_price() {
}

void Meal::update_price() {
   
}

int Meal::getID() {
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

void Meal::reduceQuantity(int n) {
  
}

void Meal::setOrderQuantity(int p) {
}

int Meal::getOrderQuantity() {
    return orderQuantity;
}

Meal::~Meal() {
}