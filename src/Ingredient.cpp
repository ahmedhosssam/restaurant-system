#include "../include/Ingredient.h"

Ingredient::Ingredient() { }

Ingredient::Ingredient(string name, int id, double price, int quantity) : name(name), id(id), price(price), quantity(quantity)
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


string Ingredient::getData(){
    return "ID: "+ to_string(id)
            + " Name: " + name
            + "\tQuantity: " + to_string(quantity) + " Items\t"
            + "\tPrice: " + to_string(price) +" \x9c";
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
    cout << i.getData();
    return out;
}

void Ingredient::reduceQuantity() {
    quantity--;
}

Ingredient::~Ingredient() {
}
