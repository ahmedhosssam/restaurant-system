#include <fstream>
#include "../include/Ingredient.h"

Ingredient::Ingredient() {
    setData();
    update_ing_in_txt();
}

Ingredient::Ingredient(string name, double price, int quantity) : name(name), price(price), quantity(quantity) {
    update_ing_in_txt();
}

double Ingredient::getPrice() {
    return price;
}

void Ingredient::setData() {
    cout << "Enter Ingredient data: \n\n";

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
         << "Price: $" << price << endl
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

void Ingredient::update_ing_in_txt() {
    fstream file("data/ingredients.txt", ios::app);
    string data = name + " " + to_string(price) + " " + to_string(quantity) + "\n"; // i.e Cheese 4 69
    string line;
   
    if (file.is_open()) {
        file << data;
    } else {
        cout << "Failed to open ingredients file\n";
    }
    file.close();
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
    --quantity;
}

Ingredient::~Ingredient() {
}
