#ifndef MEAL_H
#define MEAL_H

#include <iostream>
#include <string>
#include <vector>

#include "Ingredient.h"
#include "Stock.h"
using namespace std;

class Meal {
    public:
        Meal(string name, int quantity, vector<Ingredient*> inglist, Stock* s);
        void updateMealIng();
        void setData();
        void setMealIng();
        void update_ing();
        void calcPrice();
        void getData();
        void setOrderQuantity(int q);
        void update(int n);
        int getOrderQuantity();
        int getID();
        int getMealIng();
        int getQuantity();
        double getPrice();
        string getName();

        friend istream& operator >>(istream&,Meal*);
        friend ostream& operator <<(ostream&,Meal&);
        ~Meal();

    private:
        string name; // name of meal
        int count = 0;
        int quantity; // quantity of meal
        int orderQuantity;
        double price; // total price of meal = total of ingPrice
        vector<Ingredient*> inglist;
        Stock* z;
        int m_countt=0;

};

#endif 
