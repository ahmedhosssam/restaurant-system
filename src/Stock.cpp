#include <fstream>

#include "../include/Stock.h"

Stock::Stock() {
    ifstream ingredients("../data/ingredients.txt");

    string line;
    while(getline(ingredients, line)) {
        string i_name;
        double i_price;
        int i_quantity;

        if(ingredients >> i_name >> i_price >> i_quantity) {
            Ingredient* i = new Ingredient(i_name, i_price, i_quantity);
            ingList.push_back(i);
        }
    }
}

void Stock::add_ingredient() {
    Ingredient* a = new Ingredient();
    cin >> a;
    ingList.push_back(a);
}

void Stock::add_ingredient(Ingredient* ing) {
    ingList.push_back(ing);
}

void Stock::update_ingredient_quantity() {
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

void Stock::update_ingredient_price() {
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
        cout << "ingredient list: \n\n";
        for(int i = 0; i < static_cast<int>(ingList.size()); ++i) {
            cout << (i+1) << "- " << ingList[i] << endl;
        }
    } else {
        cout << "There are not ingredients added yet!";
    }
}

Ingredient* Stock::search_ing(int id) {
    for (int i = 0; i <  static_cast<int>(ingList.size()); ++i ) {
        if (ingList[i]->getID() == id) {
            return ingList[i];
        }
    }
}

int Stock::returnIngNum() {
    return static_cast<int>(ingList.size());
}

Stock::~Stock() {
}