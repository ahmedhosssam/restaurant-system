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
        Meal();
        Meal(Stock*);
        Meal(string name, int quantity, vector<Ingredient*> inglist);
        void update_price();
        void updateMealIng();
        void setData();
        void setMealIng();
        void print_name_price();
        void update_meal_ing();
        void calcPrice();
        void getData();
        void setOrderQuantity(int p);
        void reduceQuantity(int n);
        int getOrderQuantity();
        int getID();
        int getMealIng();
        int getQuantity();
        double getPrice();
        string getName();

        friend istream& operator >>(istream&,Meal*);
        friend ostream& operator <<(ostream&,Meal&);
        virtual ~Meal();

    private:
        string name; // name of meal
        int count = 0;
        int quantity; // quantity of meal
        double price; // total price of meal = total of ingPrice
        double orderQuantity;
        vector<Ingredient*> inglist;
        Stock* z;
        int m_countt=0;

};

#endif 
