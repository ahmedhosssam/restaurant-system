#include <iostream>
#include <string>
using namespace std;
#ifndef INGREDIANT_H
#define INGREDIANT_H


class Ingredient {
    public:
        Ingredient();
        Ingredient(string name, double price, int quantity);
        void setData();
        void getData();
        void update_quantity();
        void update_price();
        void reduceQuantity();
        int getID();
        double getPrice();
        friend istream& operator >> (istream&, Ingredient*);
        friend ostream& operator << (ostream&, Ingredient&);
        virtual ~Ingredient();

    private:
        void update_ing_in_txt(); // update the ingredient data in ingredient.txt
        string name;
        double price;
        int quantity, id;
};

#endif 
