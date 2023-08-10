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
        Meal(stock*);
        Meal(string m_name, int m_id, int quantity, Ingredient* inglist, int ingSize);
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
        string m_name;
        int m_id;
        int m_count=0;
        int quantity;
        int ingSize;
        double m_price;
        double orderQuantity;
        Ingredient* inglist;
        Ingredient** ingglist;
        stock* z;
        int m_countt=0;

};

#endif 
