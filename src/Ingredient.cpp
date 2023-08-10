#include "../include/Ingredient.h"

Ingredient::Ingredient() { }

Ingredient::Ingredient(string m_name, int m_id, double m_price, int m_quantity) : m_name(m_name), m_id(m_id), m_price(m_price), m_quantity(m_quantity)
{ }

double Ingredient::getPrice() {
    return m_price;
}

void Ingredient::setData() {
    cout << "Enter Ingredient data: \n\n";
    cout << "  Enter ID: ";
    cin >> m_id;
    cout << "  Enter name: ";
    cin.ignore();
    getline(cin, m_name);
    cout << "  Enter quantity: ";
    cin >> m_quantity;
    cout << "  Enter price: ";
    cin >> m_price;
}


string Ingredient::getData(){
    return "ID: "+ to_string(m_id)
            + " Name: " + m_name
            + "\tQuantity: " + to_string(m_quantity) + " Items\t"
            + "\tPrice: " + to_string(m_price) +" \x9c";
}

void Ingredient::update_quantity() {
    cout << "\nEdit Ingredient quantity: \n\n"
        << "  Enter new quantity: ";
    cin >> m_quantity;
}

void Ingredient::update_price() {
    cout << "\nEdit Ingredient price: \n\n"
        << "  Enter new price: ";
    cin >> m_price;
}

int Ingredient::getID() {
    return m_id;
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
    m_quantity--;
}

Ingredient::~Ingredient() {
}
