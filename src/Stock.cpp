#include "../include/Stock.h"

stock::stock() {
}

void stock::add_ingrediant() {
    Ingredient* a = new Ingredient();
    cin >> a;
    ingList.push_back(a);
}

void stock::update_ingrediant_quantity() {
    int id;
    bool found = false;

    cout<< "Enter ingredient id: ";
    cin >> id;

    for(int i = 0; i < static_cast<int>(ingList.size()); ++i) {
        if(ingList[i]->getID() == id) {
            ingList[i]->update_quantity();
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "\nNo matching ingredient found.\n";
    }
}

void stock::update_ingrediant_price() {
    int id;
    bool found = false;

    cout<<"Enter ingredient id: ";
    cin >> id;

    for(int i = 0; i < m_ingCount; ++i) {
        if(ingList[i]->getID() == id) {
            ingList[i]->update_price();
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "\nNo matching ingredient found!...\n";
    }
}

void stock::delete_ingrediant() {
    int id;
    bool found = false;

    cout << "Enter ingredient id: ";
    cin >> id;

    ingList.erase(ingList.begin() + id);

    if(!found) {
        cout << "\nNo matching ingredient found.\n";
    }
}

void stock::display_all() {
    if(ingList.size()) {
        cout << "ingredient list: \n\n";
        for(int i = 0; i < static_cast<int>(ingList.size()); ++i) {
            cout << (i+1) << "- " << ingList[i] << endl;
        }
    } else {
        cout << "There are not ingredients added yet!";
    }
}

Ingredient* stock::search_ing(int id) {
    for (int i = 0; i <  static_cast<int>(ingList.size()); ++i ) {
        if (ingList[i]->getID() == id) {
            return ingList[i];
        }
    }
}

stock::~stock() {
}