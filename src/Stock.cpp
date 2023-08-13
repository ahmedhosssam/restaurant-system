#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

#include "../include/Stock.h"

Stock::Stock() {
    //ifstream ifile("data/ingredients.txt"); // file of ingredients data
    fstream file("data/start_ing.txt"); // reading starting data for ingredients

    string line;
    string i_name;
    double i_price;
    double i_quantity;

    while (getline(file, line)) {

        // to read 
        if (file >> i_name >> i_price >> i_quantity) {
            Ingredient* i = new Ingredient(i_name, i_price, i_quantity);
            ingList.push_back(i);
        } else {
            continue;
        }
    }
    file.close();
}

void Stock::add_ingredient() {
    Ingredient* a = new Ingredient;
    ingList.push_back(a);
}

void Stock::add_ingredient(Ingredient* i) {
    ingList.push_back(i);
}

void Stock::update_ingredient_quantity() {
    int id;

    display_all();
    cout << "Enter ingredient id: ";
    cin >> id;

    if(id > static_cast<int>(ingList.size()) || id < 0)
        cout << "No matching ingredient found.\n";
    else ingList[id]->update_quantity();
}

void Stock::update_ingredient_price() {
    int id;

    display_all();
    cout<<"Enter ingredient id: ";
    cin >> id;

    if(id > static_cast<int>(ingList.size()) || id < 0)
        cout << "No matching ingredient found.\n";
    else ingList[id]->update_price();
}

void Stock::delete_ingredient() {
    int id;
    
    display_all();
    cout << "Enter ingredient id: ";
    cin >> id;

    if(id > static_cast<int>(ingList.size()) || id < 0)
        cout << "No matching ingredient found.\n";
    else ingList.erase(ingList.begin() + id);
}

void Stock::display_all() {
    if(ingList.size()) {
        cout << "Ingredients list: \n\n";

        for(int i = 0; i < static_cast<int>(ingList.size()); ++i) {
            cout << i << "- ";
            ingList[i]->getData();
        }
    } else {
        cout << "There are not ingredients added yet!\n";
    }
}

Ingredient* Stock::return_ing(int id) {
    return ingList[id];
}

int Stock::returnIngNum() {
    return static_cast<int>(ingList.size());
}

Stock::~Stock() {
}