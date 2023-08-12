#include <iostream>

#include "../include/Menu.h"
#include "../include/Meal.h"

using namespace std;

Menu::Menu() {
    
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

Menu::~Menu() {
}
