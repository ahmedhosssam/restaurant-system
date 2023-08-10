#include <iostream>

#include "../include/Menu.h"
#include "../include/Meal.h"

using namespace std;

menu::menu()
{
    m_MealSize = 50;
    mealList = new Meal[m_MealSize];
    m_mealCount = 0;

}
void menu::add_meal(stock* a)
{
    Meal* b = new Meal(a);
    cin>>b;
    mealList[m_mealCount++] = *b;

}

void menu::add_meal(Meal m)
{
    mealList[m_mealCount++] = m;
}

void menu::updateMealPrice(){
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

void menu::deleteMeal(){
    int id;
    bool found = true;
    cout<<"Enter meal id: ";
    cin >> id;
    for(int i=0;i<m_mealCount;++i){
        if(mealList[i].getID()==id){
            if(i==m_mealCount-1){
                m_mealCount--;
            }
            else{
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

void menu::display_all(){
    if(m_mealCount!=0){
        cout << "Menu :" << endl;

        for(int i = 0; i < m_mealCount; ++i)
            cout << i << "- " << mealList[i] << endl;

        cout << "<<----------------------->>" << endl << endl;
    } else {
        cout<< "The menu is empty." << endl;
    }
}

Meal* menu::getMeal(int n)
{
    Meal* ptr = &mealList[n];
    return ptr;
}

/*int* getAddress(int value) {
    int* ptr = &value; // Store the address of the variable
    return ptr; // Return the address
}*/

int menu::getMealsNumber()
{
    return m_mealCount;
}

menu::~menu()
{
    //dtor
}
