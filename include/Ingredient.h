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
        void update_quantity();
        void update_price();
        void reduceQuantity();
        double getPrice();
        int getID();
        string getData();
        friend istream& operator >>(istream&,Ingredient*);
        friend ostream& operator <<(ostream&,Ingredient&);
        virtual ~Ingredient();

    private:
        string name;
        int quantity, id;
        double price;
};

#endif // INGREDIANT_H
