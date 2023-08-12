#ifndef MEAL_H
#define MEAL_H

#include <iostream>
#include <string>
#include <vector>

#include "Ingredient.h"
#include "Stock.h"
using namespace std;

struct IngToken
{
    Ingredient* ing;
    int quantity; // quantity of each ingredient in inglist
};

class Meal {
    public:
        Meal(string name, int quantity, Stock* s); // to choose ingredients from Stock* s
        Meal(string name, int quantity, vector<Ingredient*> inglist, Stock* s);
        void updateMealIng();
        void setData();
        void setMealIng();
        void update_ing();
        void calcPrice();
        void getData();
        void setOrderQuantity(int q);
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
        int quantity; // quantity of meal
        int orderQuantity;
        double price; // total price of meal = total of ingPrice
        vector<IngToken> inglist;
        Stock* ptr_s;
};

#endif 
