#include <iostream>
#include "../include/Meal.h"

using namespace std;

Meal::Meal(string name, int quantity, Stock* s) : name(name), quantity(quantity), ptr_s(s) {
    chooseIngs();
    calcPrice();
}

Meal::Meal(Stock* s) : ptr_s(s) {
    string name;
    int quantity;
    cout << "Enter the name of the meal: "; cin >> name;
    cout << "Enter the quantity of the meal: "; cin >> quantity;
    Meal::name = name;
    Meal::quantity = quantity;
    chooseIngs();
    calcPrice();
}

Meal::Meal(string name, int quantity, vector<Ingredient*> inglist, Stock* s) : name(name), quantity(quantity), inglist(inglist), ptr_s(s) {
    calcPrice();
}

void Meal::updateMealIng() {
    int id;
    int option;
    
    for (Ingredient* i : inglist) {
        i->getData();
        cout << "--------------\n";
    }
    /*cout << "Choose ingredient by id: ";
    cin >> id;*/
    
    cout << "Choose your option:\n"
         << "\t1- Add a new ingredient to the meal.\n"
         << "\t2- Delete an ingredient.\n";
    cin >> option;
    
    switch (option)
    {
        case 1:
            {
                ptr_s->display_all();
                cout << "Choose an ingredient by id: ";
                cin >> id;
                if(id <= static_cast<int>(inglist.size()) && id >= 0) {
                    Ingredient* ing = ptr_s->return_ing(id);
                    inglist.push_back(ing);
                }
                else { 
                    cout << "No matching ingredient found, please try again.\n";
                }
                break;
            }
        case 2:
            {
                cin >> id;
                inglist.erase(inglist.begin() + id);
                break;
            }
            default:
            {
                cout << "Error: Invalid choice.\n";
                break;
            }
    }
    
}

// choose ingredients from Stock and put it into inglist
void Meal::chooseIngs() {
    int id;
    bool entering = true;

    ptr_s->display_all();
    cout << "Choose ingredients of your meal ( enter x to stop ): ";

    while(entering) {
        cin >> id;
        if(id <= ptr_s->returnIngNum() && id >= 0) {
            Ingredient* ing;
            ing = ptr_s->return_ing(id);
            inglist.push_back(ing);
        } else if (id > ptr_s->returnIngNum() || id < 0) {
            cout << "Error: out of range of ingredients numbers, please try again.\n";
        } else {
            break;
        }
    }
}

void Meal::calcPrice() {
    for (Ingredient* i : inglist) {
        total_price += i->getPrice();
    }
}

void Meal::getData() {}

void Meal::setData() {}

void Meal::setMealIng() {}

void Meal::update_ing() {}

void Meal::setOrderQuantity(int q) {}

int Meal::getOrderQuantity() { return 1; }

int Meal::getID() { return 1;}

int Meal::getMealIng() { return 1; }

ostream& operator << (ostream& out, Meal& i) {
    i.getData();
    return out;
}

istream& operator >> (istream& in, Meal* i) {
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
    return total_price * orderQuantity;
}

Meal::~Meal() {
}