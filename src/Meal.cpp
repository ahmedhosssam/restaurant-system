#include <iostream>
#include "../include/Meal.h"

using namespace std;

Meal::Meal(string name, int quantity, Stock* s) : name(name), quantity(quantity), ptr_s(s) {
    ptr_s->display_all();
    int option;
    int id;
    bool entering = true;

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

Meal::Meal(string name, int quantity, vector<Ingredient*> inglist, Stock* s) : name(name), quantity(quantity), inglist(inglist), ptr_s(s) {
    calcPrice();
}

void Meal::updateMealIng() {
    int id;
    int option;
    
    for (long unsigned int i = 0; i < inglist.size(); ++i) {
        inglist[i].ing->getData();
        cout << "--------------\n";
    }
    /*cout << "Choose ingredient by id: ";
    cin >> id;*/
    
    cout << "Choose your option:\n"
         << "\t1- Add new ingredient\n"
         << "\t2- Update the quantity of ingredient\n"
         << "\t3- Delete ingredient\n";
    cin >> option;
    
    switch (option)
    {
        case 1:
            {
                ptr_s->display_all();
                cout << "Choose ingredient by id: ";
                cin >> id;
                if(id > static_cast<int>(inglist.size()) || id < 0)
                    cout << "No matching ingredient found.\n";
                else { 
                    Ingredient* ing = ptr_s->return_ing(id);
                    inglist.push_back(ing);
                }
                break;
            }
        case 2:
            {
                cin >> id;
                Ingredient* ing = inglist[id];

            }
        case 3:
            {

            }
        
        default:
            break;
    }
    
}
void Meal::setData() {}

void Meal::setMealIng() {}

void Meal::update_ing() {}

void Meal::calcPrice() {}

void Meal::getData() {}

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
    return price * orderQuantity;
}

Meal::~Meal() {
}