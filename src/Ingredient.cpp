#include "../include/Ingredient.h"

Ingredient::Ingredient() { }

Ingredient::Ingredient(string name, double price, int quantity) : name(name), price(price), quantity(quantity)
{ }

double Ingredient::getPrice() {
    return price;
}

void Ingredient::setData() {
    cout << "Enter Ingredient data: \n\n";

    cout << "  Enter ID: ";
    cin >> id;

    cout << "  Enter name: ";
    cin.ignore();
    getline(cin, name);

    cout << "  Enter quantity: ";
    cin >> quantity;

    cout << "  Enter price: ";
    cin >> price;
}


void Ingredient::getData() {
    cout << "Name: " << name << endl
         << "Price: " << price << endl
         << "Quantity: " << quantity << endl;
    cout << "-------------\n";
}

void Ingredient::update_quantity() {
    cout << "\nEdit Ingredient quantity: \n\n"
        << "  Enter new quantity: ";
    cin >> quantity;
}

void Ingredient::update_price() {
    cout << "\nEdit Ingredient price: \n\n"
        << "  Enter new price: ";
    cin >> price;
}

int Ingredient::getID() {
    return id;
}

istream& operator >> (istream& in ,Ingredient* i) {
    i->setData();
    return in;
}

ostream& operator << (ostream& out,Ingredient& i) {
    i.getData();
    return out;
}

void Ingredient::reduceQuantity() {
    quantity--;
}

Ingredient::~Ingredient() {
}
