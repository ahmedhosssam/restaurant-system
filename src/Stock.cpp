#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

#include "../include/Stock.h"

Stock::Stock() {
    Ingredient ii("hoho", 69, 64);
    ingList.push_back(ii);

    ifstream ingredients("data/ingredients.txt");

    string line;
    string i_name;
    int i_price;
    int i_quantity;

    while(getline(ingredients, line)) {

        if(ingredients >> i_name >> i_price >> i_quantity) {
            Ingredient i(i_name, i_price, i_quantity);
            ingList.push_back(i);
        } 
    }
    ingredients.close();
}

void Stock::add_ingredient() {
    Ingredient a;
    a.setData();
    ingList.push_back(a);
}

void Stock::add_ingredient(Ingredient i) {
    ingList.push_back(i);
}

void Stock::update_ingredient_quantity() {
    int id;
    bool found = false;

    cout<< "Enter ingredient id: ";
    cin >> id;

    for(int i = 0; i < static_cast<int>(ingList.size()); ++i) {
        if(ingList[i].getID() == id) {
            ingList[i].update_quantity();
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "\nNo matching ingredient found.\n";
    }
}

void Stock::update_ingredient_price() {
    int id;
    bool found = false;

    cout<<"Enter ingredient id: ";
    cin >> id;

    for(int i = 0; i < m_ingCount; ++i) {
        if(ingList[i].getID() == id) {
            ingList[i].update_price();
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "\nNo matching ingredient found!...\n";
    }
}

void Stock::delete_ingredient() {
    int id;
    bool found = false;

    cout << "Enter ingredient id: ";
    cin >> id;

    ingList.erase(ingList.begin() + id);

    if(!found) {
        cout << "\nNo matching ingredient found.\n";
    }
}

void Stock::display_all() {
    if(ingList.size()) {
        cout << "Ingredients list: \n\n";

        for(int i = 0; i < static_cast<int>(ingList.size()); ++i) {
            cout << i << "- ";
            ingList[i].getData();
        }
    } else {
        cout << "There are not ingredients added yet!\n";
    }
}

Ingredient Stock::search_ing(int id) {
    for (int i = 0; i <  static_cast<int>(ingList.size()); ++i ) {
        if (ingList[i].getID() == id) {
            return ingList[i];
        }
    }
}

int Stock::returnIngNum() {
    return static_cast<int>(ingList.size());
}

Stock::~Stock() {
}