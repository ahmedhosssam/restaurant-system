#include <iostream>
#include "../include/Meal.h"

using namespace std;

Meal::Meal(Stock* a) {
    z = a;
    inglist = new Ingredient[25];
    m_count = 0;
    ingglist = new Ingredient*[25];
    m_countt = 0;
}

Meal::Meal() {
}

Meal::Meal(string m_name, int m_id, int quantity, Ingredient* inglist, int ingSize)
    : m_name(m_name), m_id(m_id), quantity(quantity), inglist(inglist), ingSize(ingSize) {

    calcPrice();
    m_count = 0;
}

void Meal::setData() {
    cout << "Enter the details of the meal:\n\n";
    cout << "  Enter ID: ";
    cin >> m_id;

    cout << "  Enter name: ";
    cin.ignore();
    getline(cin, m_name);

    cout << "  Enter quantity: ";
    cin >> quantity;

    cout << "  Enter price: ";
    cin >> m_price;

    for (int i = 0; i < 25; i++) {
        char choice = 'y';
        int id;

        cout << "  Enter ingredient ID ";
        cin >> id;

        Ingredient* ingAdd;
        ingAdd = z->search_ing(id);

        ingAdd->getData();
        ingglist[m_countt++] = ingAdd;

        cout << "\n  Do you want to add a new ingredient? Press y/n" << endl;
        cin >> choice;

        if (choice == 'y')
            continue;
        else if (choice == 'n')
            break;
        else {
            cout << "Invalid choice, try again" << endl;
            cin >> choice;
        }
    }

    for (int i = 0; i < m_countt; ++i) {
        ingglist[i]->getData();
    }
}

void Meal::calcPrice() {
    for (int i = 0; i < ingSize; ++i) {
        m_price += inglist[i].getPrice();
    }
}

void Meal::getData() {
    cout << "Name: " << m_name << endl;
    cout << "Quantity: " << quantity << " items" << endl;
    cout << "Price: $" << m_price << endl;
}

void Meal::print_name_price() {
    cout << " Name : " << m_name << endl << " Price : " << m_price;
}

void Meal::update_price() {
    cout << "\nEdit meal price:\n\n" << "  Enter new price: ";
    cin >> m_price;
}

int Meal::getID() {
    return m_id;
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
    return m_name;
}

double Meal::getPrice() {
    return m_price * orderQuantity;
}

void Meal::reduceQuantity(int n) {
    quantity -= n;

    for (int i = 0; i < ingSize; ++i) {
        inglist[i].reduceQuantity();
    }
}

void Meal::setOrderQuantity(int p) {
    orderQuantity = p;
}

int Meal::getOrderQuantity() {
    return orderQuantity;
}

Meal::~Meal() {
}