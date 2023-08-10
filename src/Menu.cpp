#include <iostream>

#include "../include/Menu.h"
#include "../include/Meal.h"

using namespace std;

Menu::Menu() {
    m_MealSize = 50;
    mealList = new Meal[m_MealSize];
    m_mealCount = 0;

}

void Menu::add_meal(Stock* a) {
    Meal* b = new Meal(a);
    cin>>b;
    mealList[m_mealCount++] = *b;
}

void Menu::add_meal(Meal m) {
    mealList[m_mealCount++] = m;
}

void Menu::updateMealPrice() {
    int id;
    bool found = true;
    cout<<"Enter meal id: ";
    cin >> id;
    for(int i=0;i<m_mealCount;++i){
        if(mealList[i].getID()==id){
            mealList[i].update_price();
            found = false;
        }
    }

    if(found){
        cout<<"\nNo matching meal found!...\n";
        cout<<"\nEnter any key to continue...";
    }
}

void Menu::deleteMeal() {
    int id;
    bool found = true;

    cout << "Enter meal id: ";
    cin >> id;

    for(int i = 0; i < m_mealCount; ++i) {
        if(mealList[i].getID()==id){
            if(i==m_mealCount-1) {
                m_mealCount--;
            } else {
                mealList[i]= mealList[m_mealCount-1];
                m_mealCount--;
            }
            found = false;
        }
    }
    if(found){
        cout<<"\nNo matching meal found!...\n";
    }
}

void Menu::display_all() {
    if(m_mealCount != 0) {
        cout << "Menu :" << endl;

        for(int i = 0; i < m_mealCount; ++i)
            cout << i << "- " << mealList[i] << endl;

        cout << "<<----------------------->>" << endl << endl;
    } else {
        cout<< "The menu is empty." << endl;
    }
}

Meal* Menu::getMeal(int n) {
    Meal* ptr = &mealList[n];
    return ptr;
}

int Menu::getMealsNumber() {
    return m_mealCount;
}

Menu::~Menu() {
}
