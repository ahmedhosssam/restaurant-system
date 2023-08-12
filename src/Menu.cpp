#include <iostream>
#include <fstream>
#include <sstream>

#include "../include/Menu.h"
#include "../include/Meal.h"

using namespace std;

Menu::Menu(Stock* s) : s_ptr(s) {
    ifstream meals("data/meals.txt");
    if(!meals.is_open()) {
        cerr << "Failed to open the file." << endl;
    }
    string line;
    while (getline(meals, line)) {
        istringstream iss(line);
        int num;
        string mealName;
        vector<int> ingNumbers;
        vector<Meal> ingredients; // for meal
        iss >> mealName;
        while (iss >> num) {
            ingNumbers.push_back(num);
            s_ptr->return_ing(num - 1)->getData();
        }
    }
    meals.close();
}

void Menu::add_meal(Meal* m) {
    meallist.push_back(m);
}

void Menu::deleteMeal(int i) {
    meallist.erase(meallist.begin() + i);
}

void Menu::display_all() {
    for(Meal* m : meallist) {
        m->getData();
    }
}

Meal* Menu::getMeal(int n) {
    return meallist[n];
}

int Menu::getMealsNumber() {
    return static_cast<int>(meallist.size());
}

void Menu::setStock(Stock *s) {
    s_ptr = s;
}

Menu::~Menu() {
}
