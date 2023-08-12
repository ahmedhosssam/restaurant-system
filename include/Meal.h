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
        Meal(string name, int quantity, Stock* s); // to choose ingredients from Stock* s
        Meal(string name, int quantity, vector<Ingredient*> inglist, Stock* s);
        Meal(Stock* s);
        void updateMealIng();
        void setData();
        void calcPrice();
        void getData();
        void reduceQuantity(int q);
        void setOrderQuantity(int q);
        int getOrderQuantity();
        void setQuantity(int q);
        int getQuantity();
        double getPrice();
        string getName();
        vector<Ingredient*> getIngredients();

        friend istream& operator >>(istream&,Meal*);
        friend ostream& operator <<(ostream&,Meal&);
        ~Meal();

    private:
        void chooseIngs(); // choose ingredients from Stock and put it into inglist

        string name; // name of meal
        int quantity; // quantity of meal
        int orderQuantity = 0;
        double total_price = 0.00; // total price of meal = total of ingPrice
        vector<Ingredient*> inglist;
        Stock* ptr_s;
};

#endif 
