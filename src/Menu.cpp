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
        vector<Ingredient*> ingredients; // for meal
        iss >> mealName;
        cout << mealName << endl;
        while (iss >> num) {
            Ingredient* ing = s_ptr->return_ing(num);
            ingredients.push_back(ing);
        }
        Meal* newMeal = new Meal(mealName, 99, ingredients, s_ptr);
        meallist.push_back(newMeal);
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
    for (Meal* m : meallist) {
        delete m;  
    }
    meallist.clear();  

    // You should also delete any dynamically allocated ingredients that may be left
    for (Meal* m : meallist) {
        const vector<Ingredient*>& ingredients = m->getIngredients();
        for (Ingredient* ing : ingredients) {
            delete ing;  // Delete the Ingredient object
        }
    }
}